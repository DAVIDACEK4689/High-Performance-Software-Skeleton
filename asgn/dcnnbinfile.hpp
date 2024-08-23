#ifndef dcnnbinfile_hpp_
#define dcnnbinfile_hpp_

#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include <utility>
#include <array>

#include "tagged.hpp"

namespace dcnnasgn {

	inline constexpr std::uint8_t byteswap(std::uint8_t n) noexcept
	{
		return n;
	}

	inline constexpr std::uint16_t byteswap(std::uint16_t n) noexcept
	{
		return (n << 8) ^ (n >> 8);
	}

	inline constexpr std::uint32_t byteswap(std::uint32_t n) noexcept
	{
		return (n << 24) ^ ((n << 8) & 0xFF0000) ^ ((n >> 8) & 0xFF00) ^ (n >> 24);
	}

	template< typename T>
	inline void binary_read(std::istream& ifs, T& v)
	{
		ifs.read(reinterpret_cast<char*>(&v), sizeof(T));
		if constexpr (sizeof(T) != 1 && std::endian::native != std::endian::big)
		{
			v = byteswap(v);
		}
	}

	template< typename T>
	inline void binary_read(std::istream& ifs, T* p, std::size_t n)
	{
		ifs.read(reinterpret_cast<char*>(p), sizeof(T) * n);
		if constexpr (sizeof(T) != 1 && std::endian::native != std::endian::big)
		{
			T* e = p + n;
			for (; p != e; ++p)
			{
				*p = byteswap(*p);
			}
		}
	}

	template< tagged::is_range range_t, typename indices>
	struct range_helper;

	template< tagged::is_range range_t, std::size_t ... IL>
	struct range_helper< range_t, std::index_sequence< IL ...>> {

		template< std::size_t I, typename X>
		static auto cast_one(const std::array<X, sizeof...(IL)>& a)
		{
			return tagged::range_class< typename range_t::template get_tag< I>>(a[I]);
		}

		template< typename X>
		static range_t cast(const std::array<X, sizeof...(IL)>& a)
		{
			return (... & cast_one< IL>(a));
		}

		template< typename X>
		static void print(const std::array<X, sizeof...(IL)>& a)
		{
			std::cout << "Index sizes:";
			(..., (std::cout << " " << a[IL]));
			std::cout << std::endl;
		}
	};

	template< typename E, tagged::tag ... TL>
	inline auto load_data(const std::filesystem::path& ifn)
	{
		static constexpr std::size_t dims = sizeof...(TL);
		using range_t = tagged::range_class< TL ...>;
		using vector_t = tagged::tensor_class< E, TL ...>;

		std::ifstream ifs(ifn, std::ios_base::binary);

		if (!ifs.good())
		{
			throw std::runtime_error("Cannot open file \"" + ifn.generic_string() + "\"");
		}

		ifs.seekg(0, std::ios_base::end);
		auto ifsize = ifs.tellg();
		ifs.seekg(0, std::ios_base::beg);

		//std::cout << "File size: " << ifsize << std::endl;

		std::uint16_t zero;
		binary_read(ifs, zero);
		//std::cout << "Zero: " << zero << std::endl;

		std::uint8_t element_bits;
		binary_read(ifs, element_bits);
		//std::cout << "Element bits: " << (unsigned)element_bits << std::endl;

		std::uint8_t dimensions;
		binary_read(ifs, dimensions);
		//std::cout << "Dimensions: " << (unsigned)dimensions << std::endl;

		if (dimensions != dims)
		{
			throw std::runtime_error("Mismatched number of dimensions");
		}

		std::array<std::uint32_t, dims> index_sizes;
		binary_read(ifs, index_sizes.data(), dims);

		using helper = range_helper<range_t, std::make_index_sequence< dims>>;
		//helper::print(index_sizes);
		range_t input_r = helper::cast(index_sizes);

		vector_t vec(input_r);

		binary_read(ifs, vec.flat_data(), ifsize);

		return vec;
	}

}

#endif
