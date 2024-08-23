// dcnnfmwkmain.cpp - DCNN - The Tests
//

#include "dcnnsol.hpp"
#include "dcnnasgn.hpp"
#include "fmwkng.hpp"

#include <filesystem>

namespace dcnnmain {

	template< typename PP>
	struct run_thread_ftor {

		run_thread_ftor(dcnnasgn::global_state<PP>& gsr)
			: gs(gsr)
		{}

		template< typename CTX>
		void operator()(CTX&& ctx5) const
		{
			using namespace fmwkng;

			dcnnasgn::thread_state<PP> ts(gs);
			std::mt19937_64 eng(std::mt19937_64::default_seed + ctx5.thread_index());
			std::uniform_int_distribution<std::size_t> distro(0, gs.train_labels.range().size() - 1);
			auto input_index_generator = [&eng, &distro]() {
				return dcnnasgn::input_index(distro(eng));
				};

			auto N = fmwkng::get<total>(ctx5) / (fmwkng::get<superbatch>(ctx5) * fmwkng::get<minibatch>(ctx5));
			for (std::size_t i = 0; i < N; ++i)
			{
				ts.minibatch_init(input_index_generator);

				{
					auto&& ctx6 = measurement<time>(ctx5, ts.minibatch_run_complexity(gs));
					ts.minibatch_run(gs);
					std::size_t h = (std::size_t)std::round(ts.loss);
					store_result<loss>(ctx6, h);
				}
				{
					auto&& ctx7 = sequential(ctx5);
					ts.minibatch_collect(gs);
				}
			}
		}

		dcnnasgn::global_state< PP> & gs;
	};

	template< typename PP>
	struct run_platform_ftor {
		template< typename CTX>
		void operator()(CTX&& ctx1) const
		{
			using namespace fmwkng;
			for (auto&& ctx2 : for_range<minibatch>(ctx1))
			{
				dcnnasgn::global_state<PP> gs(fmwkng::get<minibatch>(ctx2));

				auto dfp = fmwkng::count<data_folder>(ctx2);
				std::filesystem::path df(!!dfp ? *dfp : std::string("data"));

				gs.read_data(df);

				for (auto&& ctx3 : for_range<total>(ctx2))
				{
					for (auto&& ctx4 : for_range<superbatch>(ctx3))
					{
						std::mt19937_64 eng;
						gs.init(eng);
#ifdef NDEBUG
						for_parallel(ctx4, run_thread_ftor(gs), fmwkng::get<superbatch>(ctx4));
#else
						for_parallel(ctx4, run_thread_ftor(gs), fmwkng::get<superbatch>(ctx4), 1);
#endif
					}
				}
			}
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
	using PP = dcnnsol::permutation_policy;

	using namespace fmwkng;
	root<dcnnmain::root_config> ctx1(argc, argv, dcnnmain::gold_master().collect());
	//std::cout << "Running..." << std::endl;
	//for (auto&& ctx1 : for_range<dcnnmain::data_folder>(ctx0))
		for_platforms(ctx1, dcnnmain::run_platform_ftor<PP>());
	//std::cout << "Done." << std::endl;
	return 0;
}
