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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-91.0762,40)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-91.0762,40)));
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
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::platform_sse,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-91.0762,40)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::platform_sse,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(0));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.391,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12694,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28793,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30878,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36559,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30172,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(1));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.3814,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12602,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28378,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30838,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36649,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.29676,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(2));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.373,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12652,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28133,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30924,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36599,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28994,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(3));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.3804,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12692,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28798,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30937,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36702,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.2891,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(4));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.3954,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12602,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.2873,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30929,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36794,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30481,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(5));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.3803,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12718,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28673,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30829,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36488,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.29318,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(6));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.3934,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12656,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28202,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30895,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36573,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.31012,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(7));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-11.3814,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.12719,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28794,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.30913,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.36725,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-2.28988,1)));
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
