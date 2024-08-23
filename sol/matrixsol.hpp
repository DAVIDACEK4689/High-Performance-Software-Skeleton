#ifndef matrixsol_hpp
#define matrixsol_hpp

#include <cstddef>
#include <cstdint>

namespace matrixsol {

	template< typename policy>
	class matrix {
	public:
		using matrix_element = std::uint16_t;

		matrix(std::size_t vs, std::size_t hs)
		{
		}

		std::size_t vsize() const
		{
			return 1;
		}

		std::size_t hsize() const
		{
			return 1;
		}

		void set(std::size_t i, std::size_t j, matrix_element e)
		{
		}

		matrix_element get(std::size_t i, std::size_t j) const
		{
			return 1;
		}

		void assign_mul(const matrix& a, const matrix& b)
		{
		}
	};

	/*
	struct policy_scalar {
	};
	*/
	struct policy_sse {
	};

#ifdef USE_AVX
	struct policy_avx {
	};
#endif

#ifdef USE_AVX512
	struct policy_avx512 {
	};
#endif
}

#endif
