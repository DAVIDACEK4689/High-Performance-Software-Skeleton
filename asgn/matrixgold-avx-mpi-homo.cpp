#include "fmwkng.hpp"
#include "matrixasgn.hpp"

namespace matrixmain {
    static fmwkng::gold_pair gr_1()
    {
        fmwkng::gold_pair rv;
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::root_tag<matrixmain::root_config>,fmwkng::impl::element_sense::OPEN>>("mpi-homo"));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::impl::version_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_platforms_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-103.041,40)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1()
    {
        fmwkng::impl::element_list rv;
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::root_tag<matrixmain::root_config>,fmwkng::impl::element_sense::OPEN>>("mpi-homo"));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_platforms_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-103.041,40)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1()
    {
        fmwkng::impl::element_list rv = gp_1();
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::platform_avx,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-103.041,40)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::platform_avx,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(0));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8793,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(0));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47874,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57693,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64621,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.65272,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.52473,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(1));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8701,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_2()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(1));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47883,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57669,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64523,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.6487,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.52061,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(2));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8925,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_3()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(2));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47822,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.5761,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64516,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.65016,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.5429,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(3));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8855,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_4()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(3));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47818,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57684,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64596,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.65067,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53379,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(4));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8783,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_5()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(4));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47882,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57674,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64617,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.6518,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.52472,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(5));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8874,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_6()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(5));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47796,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57687,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64443,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64975,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53837,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(6));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8746,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_7()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(6));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47887,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57682,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64644,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64957,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.5229,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(7));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-12.8729,5)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_8()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(7));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(64,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.47881,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57698,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.64644,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.65117,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.51947,1)));
        return rv;
    }
    static fmwkng::gold_data gold_results_()
    {
        fmwkng::gold_data rv;
        rv.insert(gr_1_1_1_1_1());
        rv.insert(gr_1_1_1_1_2());
        rv.insert(gr_1_1_1_1_3());
        rv.insert(gr_1_1_1_1_4());
        rv.insert(gr_1_1_1_1_5());
        rv.insert(gr_1_1_1_1());
        rv.insert(gr_1_1_1_2_1());
        rv.insert(gr_1_1_1_2_2());
        rv.insert(gr_1_1_1_2_3());
        rv.insert(gr_1_1_1_2_4());
        rv.insert(gr_1_1_1_2_5());
        rv.insert(gr_1_1_1_2());
        rv.insert(gr_1_1_1_3_1());
        rv.insert(gr_1_1_1_3_2());
        rv.insert(gr_1_1_1_3_3());
        rv.insert(gr_1_1_1_3_4());
        rv.insert(gr_1_1_1_3_5());
        rv.insert(gr_1_1_1_3());
        rv.insert(gr_1_1_1_4_1());
        rv.insert(gr_1_1_1_4_2());
        rv.insert(gr_1_1_1_4_3());
        rv.insert(gr_1_1_1_4_4());
        rv.insert(gr_1_1_1_4_5());
        rv.insert(gr_1_1_1_4());
        rv.insert(gr_1_1_1_5_1());
        rv.insert(gr_1_1_1_5_2());
        rv.insert(gr_1_1_1_5_3());
        rv.insert(gr_1_1_1_5_4());
        rv.insert(gr_1_1_1_5_5());
        rv.insert(gr_1_1_1_5());
        rv.insert(gr_1_1_1_6_1());
        rv.insert(gr_1_1_1_6_2());
        rv.insert(gr_1_1_1_6_3());
        rv.insert(gr_1_1_1_6_4());
        rv.insert(gr_1_1_1_6_5());
        rv.insert(gr_1_1_1_6());
        rv.insert(gr_1_1_1_7_1());
        rv.insert(gr_1_1_1_7_2());
        rv.insert(gr_1_1_1_7_3());
        rv.insert(gr_1_1_1_7_4());
        rv.insert(gr_1_1_1_7_5());
        rv.insert(gr_1_1_1_7());
        rv.insert(gr_1_1_1_8_1());
        rv.insert(gr_1_1_1_8_2());
        rv.insert(gr_1_1_1_8_3());
        rv.insert(gr_1_1_1_8_4());
        rv.insert(gr_1_1_1_8_5());
        rv.insert(gr_1_1_1_8());
        rv.insert(gr_1_1_1());
        rv.insert(gr_1_1());
        rv.insert(gr_1());
        return rv;
    }
    static fmwkng::gold_holder gh_(gold_master(), gold_results_);
}
