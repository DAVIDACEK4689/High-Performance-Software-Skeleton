#include "matrixasgn.hpp"

#include "fmwkng.hpp"

#include "matrixsol.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

///////////////////////////////

namespace matrixmain {
	template<typename G>
	struct run_thread_ftor {
		template< typename CTX>
		void operator()(CTX&& ctx2) const
		{
			using namespace fmwkng;
			using policy = typename platform_t<decltype(ctx2)>::policy;
			for (auto&& ctx3 : for_range<size>(ctx2))
			{
				G gen(
					std::mt19937_64::default_seed + ctx2.thread_index()
				);

				auto s = get<size>(ctx3);

				using matrix_t = matrixsol::matrix<policy>;
				matrix_t a(s, s);
				matrix_t b(s, s);
				matrix_t c(s, s);

				matrixasgn::fill_matrix(gen, a);
				matrixasgn::fill_matrix(gen, b);

				for (auto&& ctx5 : auto_measurement<repeat_policy>(ctx3, 1024))
				{
					for (auto i : for_index<repeats>(ctx5))
					{
						c.assign_mul(a, b);
					}
					if (stop_for_results(ctx5))
					{
						std::size_t h = matrixasgn::chksum(c);
						store_result<chksum>(ctx5, h);
					}
				}

				/*{
					auto g = guard(ctx3);
					matrixasgn::verify(std::cout, c, a, b);
				}*/
			}
		}
	};

	template<typename G>
	struct run_platform_ftor {
		template< typename CTX>
		void operator()(CTX&& ctx1) const
		{
			using namespace fmwkng;
#ifdef NDEBUG
			for_parallel(ctx1, run_thread_ftor<G>());
#else
			run_thread_ftor<G>()(ctx1);
#endif
		}
	};

	fmwkng::gold_holder& gold_master()
	{
		static fmwkng::gold_holder the;
		return the;
	}
}


int main(int argc, char** argv)
{
	using namespace fmwkng;
	root<matrixmain::root_config> ctx1(argc, argv, matrixmain::gold_master().collect());
	//std::cout << "Running..." << std::endl;
	//for_platforms(ctx1, matrixmain::run_platform_ftor< matrixasgn::policy_zero>());
	for_platforms(ctx1, matrixmain::run_platform_ftor< matrixasgn::policy_random>());
	//for_platforms(ctx1, matrixmain::run_platform_ftor< matrixasgn::policy_one>());
	//std::cout << "Done." << std::endl;
	return 0;
}

///////////////////////////////
