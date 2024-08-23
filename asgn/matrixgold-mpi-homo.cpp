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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-106.054,40)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-106.054,40)));
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
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::platform_avx512,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-106.054,40)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::platform_avx512,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(0));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.3228,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53766,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.72268,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.75869,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.78988,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.51394,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(1));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.0798,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53776,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.7238,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.76011,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.78763,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.27052,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(2));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.1951,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53766,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.72284,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.75748,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.78947,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.38761,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(3));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.2883,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53746,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.7236,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.75748,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.78827,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.4815,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(4));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.1225,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53775,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.72377,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.75893,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.78785,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.31419,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(5));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.3934,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53709,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.72338,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.7602,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.79848,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.57426,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(6));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.3053,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53712,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.72337,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.75835,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.78862,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.49787,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(7));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-13.3464,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.53759,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.72362,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.7589,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.79848,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.5278,1)));
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
