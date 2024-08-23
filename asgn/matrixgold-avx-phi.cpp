#include "fmwkng.hpp"
#include "matrixasgn.hpp"

namespace matrixmain {
    static fmwkng::gold_pair gr_1()
    {
        fmwkng::gold_pair rv;
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::root_tag<matrixmain::root_config>,fmwkng::impl::element_sense::OPEN>>("phi"));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::impl::version_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_platforms_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-31.7781,40)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1()
    {
        fmwkng::impl::element_list rv;
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::root_tag<matrixmain::root_config>,fmwkng::impl::element_sense::OPEN>>("phi"));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-31.7781,40)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-31.7781,40)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.96825,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.617086,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.815185,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.879365,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.900779,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.755837,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(1));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.96809,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.618559,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.812022,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.877317,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.900472,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_2_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_2();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.759724,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(2));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.97109,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.618975,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.812943,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.879186,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.90159,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_3_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_3();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.758391,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(3));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.97955,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.619601,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.813704,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.873713,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.902849,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_4_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_4();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.769682,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(4));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.96695,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.618742,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.807044,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.873088,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.901213,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_5_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_5();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.766863,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(5));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.975,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.617063,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.80876,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.877398,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.9013,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_6_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_6();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.77048,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(6));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.96893,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.618727,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.812394,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.876058,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.901984,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_7_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_7();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.75977,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(7));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(64,1024,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(64));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-3.98025,5)));
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
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.619103,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(128,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(8));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.815005,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(256,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.873062,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(512,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.901588,1)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_8_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_8();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<matrixmain::size,fmwkng::impl::element_sense::OPEN>>(std::make_pair(1024,fmwkng::logarithmic(64,1024,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<matrixmain::repeats,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::auto_measurement_tag<matrixmain::repeat_policy>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(-0.771489,1)));
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
