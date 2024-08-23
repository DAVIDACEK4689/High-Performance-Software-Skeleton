#include "fmwkng.hpp"
#include "dcnnasgn.hpp"

namespace dcnnmain {
    static fmwkng::gold_pair gr_1()
    {
        fmwkng::gold_pair rv;
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::root_tag<dcnnmain::root_config>,fmwkng::impl::element_sense::OPEN>>("phi"));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::impl::version_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_platforms_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::minibatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160,160,5)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::total,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160000,160000,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(8,8,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(1859.68,1000)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1()
    {
        fmwkng::impl::element_list rv;
        rv.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::root_tag<dcnnmain::root_config>,fmwkng::impl::element_sense::OPEN>>("phi"));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_platforms_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::minibatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160,160,5)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::total,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160000,160000,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(8,8,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(1859.68,1000)));
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
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::platform_sse,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::minibatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160,160,5)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::total,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160000,160000,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(8,8,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(1859.68,1000)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::platform_sse,fmwkng::impl::element_sense::OPEN>>(std::monostate{}));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::minibatch,fmwkng::impl::element_sense::OPEN>>(std::make_pair(160,fmwkng::logarithmic(160,160,5))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::total,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(160000,160000,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(8,8,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(1859.68,1000)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::minibatch,fmwkng::impl::element_sense::OPEN>>(std::make_pair(160,fmwkng::logarithmic(160,160,5))));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::total,fmwkng::impl::element_sense::OPEN>>(std::make_pair(160000,fmwkng::logarithmic(160000,160000,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(fmwkng::logarithmic(8,8,2)));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(1859.68,1000)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::total,fmwkng::impl::element_sense::OPEN>>(std::make_pair(160000,fmwkng::logarithmic(160000,160000,2))));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(std::make_pair(8,fmwkng::logarithmic(8,8,2))));
        rv.key.push_back(std::make_unique<fmwkng::impl::config_element<fmwkng::all_threads_tag,fmwkng::impl::element_sense::OPEN>>(std::monostate()));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(1859.68,1000)));
        return rv;
    }
    static fmwkng::impl::element_list gp_1_1_1_1_1_1()
    {
        fmwkng::impl::element_list rv = gp_1_1_1_1_1();
        rv.push_back(std::make_unique<fmwkng::impl::element_t<dcnnmain::superbatch,fmwkng::impl::element_sense::OPEN>>(std::make_pair(8,fmwkng::logarithmic(8,8,2))));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_1()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(0));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(230.801,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_2()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(1));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(230.707,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_3()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(2));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(237.539,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_4()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(3));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(237.73,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_5()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(4));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(230.777,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_6()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(5));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(230.699,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_7()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(6));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(230.704,125)));
        return rv;
    }
    static fmwkng::gold_pair gr_1_1_1_1_1_1_8()
    {
        fmwkng::gold_pair rv;
        rv.key = gp_1_1_1_1_1_1();
        rv.key.push_back(std::make_unique<fmwkng::impl::element_t<fmwkng::impl::parallel_tag,fmwkng::impl::element_sense::OPEN>>(7));
        rv.value.push_back(std::make_unique<fmwkng::impl::result_element<fmwkng::impl::measurement_tag<dcnnmain::time>,fmwkng::impl::element_sense::CLOSE>>(std::make_pair(230.725,125)));
        return rv;
    }
    static fmwkng::gold_data gold_results_()
    {
        fmwkng::gold_data rv;
        rv.insert(gr_1_1_1_1_1_1_1());
        rv.insert(gr_1_1_1_1_1_1_2());
        rv.insert(gr_1_1_1_1_1_1_3());
        rv.insert(gr_1_1_1_1_1_1_4());
        rv.insert(gr_1_1_1_1_1_1_5());
        rv.insert(gr_1_1_1_1_1_1_6());
        rv.insert(gr_1_1_1_1_1_1_7());
        rv.insert(gr_1_1_1_1_1_1_8());
        rv.insert(gr_1_1_1_1_1_1());
        rv.insert(gr_1_1_1_1_1());
        rv.insert(gr_1_1_1_1());
        rv.insert(gr_1_1_1());
        rv.insert(gr_1_1());
        rv.insert(gr_1());
        return rv;
    }
    static fmwkng::gold_holder gh_(gold_master(), gold_results_);
}
