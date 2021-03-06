/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2016

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     
*/

#include "set/hdr_intrusive_skiplist_set_rcu.h"

#include <cds/urcu/signal_threaded.h>
#include <cds/intrusive/skip_list_rcu.h>
#include "map/print_skiplist_stat.h"

namespace set {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
    namespace {
        typedef cds::urcu::gc< cds::urcu::signal_threaded<> > rcu_type;
    }
#endif

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmp()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_less()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmpmix()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
                ,co::compare< cmp<item> >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmp_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::stat< ci::skip_list::stat<> >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_less_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::opt::disposer< faked_disposer >
                ,co::stat< ci::skip_list::stat<> >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmpmix_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::compare< cmp<item> >
                ,co::stat< ci::skip_list::stat<> >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmp_xorshift()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::compare< cmp<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::xorshift >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_less_xorshift()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::xorshift >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmpmix_xorshift()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::compare< cmp<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::skip_list::random_level_generator< ci::skip_list::xorshift >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmp_xorshift_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::compare< cmp<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::xorshift >
                ,co::stat< ci::skip_list::stat<> >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_less_xorshift_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::skip_list::random_level_generator< ci::skip_list::xorshift >
                ,co::stat< ci::skip_list::stat<> >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmpmix_xorshift_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::opt::disposer< faked_disposer >
                ,co::compare< cmp<item> >
                ,ci::skip_list::random_level_generator< ci::skip_list::xorshift >
                ,co::stat< ci::skip_list::stat<> >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }


    //*********
    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmp_pascal()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::compare< cmp<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::turbo_pascal >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_less_pascal()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::turbo_pascal >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmpmix_pascal()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::compare< cmp<item> >
                ,co::item_counter< cds::atomicity::item_counter >
                ,ci::skip_list::random_level_generator< ci::skip_list::turbo_pascal >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmp_pascal_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::turbo_pascal >
                ,co::stat< ci::skip_list::stat<> >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_less_pascal_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,ci::skip_list::random_level_generator< ci::skip_list::turbo_pascal >
                ,co::stat< ci::skip_list::stat<> >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

    void IntrusiveSkipListSetRCU::skiplist_rcu_sht_base_cmpmix_pascal_stat()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< ci::skip_list::node< rcu_type> > item;

        typedef ci::SkipListSet< rcu_type, item,
            ci::skip_list::make_traits<
                ci::opt::hook< ci::skip_list::base_hook< co::gc<rcu_type> > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::compare< cmp<item> >
                ,ci::skip_list::random_level_generator< ci::skip_list::turbo_pascal >
                ,co::stat< ci::skip_list::stat<> >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >   set_type;

        test_skiplist<set_type, misc::print_skiplist_stat<set_type::stat> >();
#endif
    }

}   // namespace set
