#ifndef bsearchsol_hpp_
#define bsearchsol_hpp_

#include <cstdint>
#include <utility>

///////////////////////////////

namespace bsearchsol {

	using data_element = std::int32_t;

	template< typename policy>
	class bsearch_inner {
	public:
		bsearch_inner(const data_element* data, std::size_t size)
		{
		}
	};

	template< typename policy>
	class bsearch_outer {
	public:
		bsearch_outer(const bsearch_inner< policy>& inner, std::size_t osize)
		{
		}

		void bucketize(const data_element* data)	// size of data is osize
		{
		}

		using bucket_rv = std::pair< const data_element*, std::size_t>;

		bucket_rv bucket(std::size_t k) const
		{
			return bucket_rv(0, 0);	// return reference to bucket contents
		}
	};

	struct policy_scalar {
	};

	struct policy_sse {
	};

	struct policy_avx {
	};

	struct policy_avx512 {
	};

}
#endif

