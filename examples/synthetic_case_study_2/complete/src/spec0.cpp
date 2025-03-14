// /////////////////////////////////////////////////////////////////////////
// C++ code automatically generated by hif2sc
// Part of HIFSuite - Version 
// Site: www.hifsuite.com - Contact: hifsuite@edalab.it
//
// HIFSuite copyright: EDALab s.r.l. - Networked Embedded Systems
// Site: www.edalab.it - Contact: info@edalab.it
// /////////////////////////////////////////////////////////////////////////


#include "../inc/spec0.hpp"


void spec0::hif_cone__24__0()
{
    _13_ = muffin::inject( hif_fault_node.instance, 0ULL, 1ULL, !(*hif_a2t_data.a_1
            ) );
    _25_ = muffin::inject( hif_fault_node.instance, 1ULL, 1ULL, !(*hif_a2t_data.b_1
            ) );
    _30_ = muffin::inject( hif_fault_node.instance, 2ULL, 1ULL, !_37_ );
    _31_ = muffin::inject( hif_fault_node.instance, 3ULL, 1ULL, !(*hif_a2t_data.c_1
            ) );
    _05_ = muffin::inject( hif_fault_node.instance, 4ULL, 1ULL, _13_ && *hif_a2t_data.b_1
         );
    _08_ = muffin::inject( hif_fault_node.instance, 5ULL, 1ULL, _30_ && *hif_a2t_data.c_1
         );
    _16_ = muffin::inject( hif_fault_node.instance, 6ULL, 1ULL, _37_ && *hif_a2t_data.c_1
         );
    _35_ = muffin::inject( hif_fault_node.instance, 7ULL, 1ULL, _25_ && *hif_a2t_data.a_1
         );
    _36_ = muffin::inject( hif_fault_node.instance, 8ULL, 1ULL, _31_ && _37_ );
    _00_ = muffin::inject( hif_fault_node.instance, 9ULL, 1ULL, _35_ && _36_ );
    _06_ = muffin::inject( hif_fault_node.instance, 10ULL, 1ULL, _05_ && _36_ );
    _14_ = muffin::inject( hif_fault_node.instance, 11ULL, 1ULL, _08_ && _35_ );
    _17_ = muffin::inject( hif_fault_node.instance, 12ULL, 1ULL, _16_ && *hif_a2t_data.a_1
         );
    _32_ = muffin::inject( hif_fault_node.instance, 13ULL, 1ULL, _30_ && _31_ );
    _01_ = muffin::inject( hif_fault_node.instance, 14ULL, 1ULL, !_00_ );
    _07_ = muffin::inject( hif_fault_node.instance, 15ULL, 1ULL, !_06_ );
    _11_ = muffin::inject( hif_fault_node.instance, 16ULL, 1ULL, _05_ && _08_ );
    _15_ = muffin::inject( hif_fault_node.instance, 17ULL, 1ULL, !_14_ );
    _18_ = muffin::inject( hif_fault_node.instance, 18ULL, 1ULL, !_17_ );
    _33_ = muffin::inject( hif_fault_node.instance, 19ULL, 1ULL, _32_ && *hif_a2t_data.a_1
         );
    _12_ = muffin::inject( hif_fault_node.instance, 20ULL, 1ULL, !_11_ );
    _19_ = muffin::inject( hif_fault_node.instance, 21ULL, 1ULL, _01_ && _07_ );
    _21_ = muffin::inject( hif_fault_node.instance, 22ULL, 1ULL, _15_ && _18_ );
    _34_ = muffin::inject( hif_fault_node.instance, 23ULL, 1ULL, !_33_ );
    _20_ = muffin::inject( hif_fault_node.instance, 24ULL, 1ULL, _19_ && _34_ );
    _22_ = muffin::inject( hif_fault_node.instance, 25ULL, 1ULL, _12_ && _21_ );
    _23_ = muffin::inject( hif_fault_node.instance, 26ULL, 1ULL, _20_ && _22_ );
    _24_ = muffin::inject( hif_fault_node.instance, 27ULL, 1ULL, !_23_ );
}


void spec0::hif_cone__29__0()
{
    _13_ = muffin::inject( hif_fault_node.instance, 28ULL, 1ULL, !(*hif_a2t_data.a_1
            ) );
    _30_ = muffin::inject( hif_fault_node.instance, 29ULL, 1ULL, !_37_ );
    _31_ = muffin::inject( hif_fault_node.instance, 30ULL, 1ULL, !(*hif_a2t_data.c_1
            ) );
    _05_ = muffin::inject( hif_fault_node.instance, 31ULL, 1ULL, _13_ && *hif_a2t_data.b_1
         );
    _08_ = muffin::inject( hif_fault_node.instance, 32ULL, 1ULL, _30_ && *hif_a2t_data.c_1
         );
    _36_ = muffin::inject( hif_fault_node.instance, 33ULL, 1ULL, _31_ && _37_ );
    _02_ = muffin::inject( hif_fault_node.instance, 34ULL, 1ULL, *hif_a2t_data.a_1
             && *hif_a2t_data.b_1 );
    _06_ = muffin::inject( hif_fault_node.instance, 35ULL, 1ULL, _05_ && _36_ );
    _03_ = muffin::inject( hif_fault_node.instance, 36ULL, 1ULL, _02_ && _36_ );
    _07_ = muffin::inject( hif_fault_node.instance, 37ULL, 1ULL, !_06_ );
    _09_ = muffin::inject( hif_fault_node.instance, 38ULL, 1ULL, _02_ && _08_ );
    _11_ = muffin::inject( hif_fault_node.instance, 39ULL, 1ULL, _05_ && _08_ );
    _04_ = muffin::inject( hif_fault_node.instance, 40ULL, 1ULL, !_03_ );
    _10_ = muffin::inject( hif_fault_node.instance, 41ULL, 1ULL, !_09_ );
    _12_ = muffin::inject( hif_fault_node.instance, 42ULL, 1ULL, !_11_ );
    _26_ = muffin::inject( hif_fault_node.instance, 43ULL, 1ULL, _04_ && _07_ );
    _27_ = muffin::inject( hif_fault_node.instance, 44ULL, 1ULL, _10_ && _12_ );
    _28_ = muffin::inject( hif_fault_node.instance, 45ULL, 1ULL, _26_ && _27_ );
    _29_ = muffin::inject( hif_fault_node.instance, 46ULL, 1ULL, !_28_ );
}



spec0::spec0() :
    hif_fault_node(muffin::hif_next_instance_counter(), 49ULL),
    b_1_old(false),
    a_1_old(false),
    clock_old(false),
    hif_a2t_data(
    nullptr,
    nullptr,
    nullptr,
    nullptr),
    _00_(false),
    _01_(false),
    _02_(false),
    _03_(false),
    _04_(false),
    _05_(false),
    _06_(false),
    _07_(false),
    _08_(false),
    _09_(false),
    _10_(false),
    _11_(false),
    _12_(false),
    _13_(false),
    _14_(false),
    _15_(false),
    _16_(false),
    _17_(false),
    _18_(false),
    _19_(false),
    _20_(false),
    _21_(false),
    _22_(false),
    _23_(false),
    _24_(false),
    _25_(false),
    _26_(false),
    _27_(false),
    _28_(false),
    _29_(false),
    _30_(false),
    _31_(false),
    _32_(false),
    _33_(false),
    _34_(false),
    _35_(false),
    _36_(false),
    _37_(false),
    _37__new(false),
    process_in_queue(false),
    flag_process_process_0_executed(false),
    flag_pos_clock(false)
{
    if (hif_fault_list_root != nullptr)
    {
        hif_fault_list_root->prev = &hif_fault_node;
        hif_fault_node.next = hif_fault_list_root;
    }
    hif_fault_list_root = &hif_fault_node;
}


spec0::~spec0()
{}


void spec0::process_process_0()
{
    hif_cone__24__0();
    _37__new = muffin::inject( hif_fault_node.instance, 47ULL, 1ULL, _24_ );
    hif_cone__29__0();
    *hif_a2t_data.c_1 = muffin::inject( hif_fault_node.instance, 48ULL, 1ULL, _29_
         );
}


void spec0::update_input_queue( bool synch_phase )
{
    process_in_queue = false;
    if (*hif_a2t_data.clock != clock_old)
    {
        clock_old = *hif_a2t_data.clock;
        if (*hif_a2t_data.clock == true)
        {
            flag_pos_clock = true;
        }
        else
        {
            flag_pos_clock = false;
        }
        process_in_queue = true;
    }
    else
    {
        flag_pos_clock = false;
    }
    a_1_old = *hif_a2t_data.a_1;
    b_1_old = *hif_a2t_data.b_1;
}


void spec0::update_event_queue()
{
    process_in_queue = false;
    update_input_queue( false );
    _37_ = _37__new;
}


void spec0::flag_elaboration()
{
    flag_process_process_0_executed = false;
    if (flag_pos_clock)
    {
        process_process_0();
        flag_process_process_0_executed = true;
    }
}


void spec0::start_of_simulation()
{
    process_process_0();
    flag_process_process_0_executed = true;
}


void spec0::initialize()
{
    start_of_simulation();
}




