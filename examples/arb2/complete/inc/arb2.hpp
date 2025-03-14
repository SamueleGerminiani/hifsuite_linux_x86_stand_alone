// /////////////////////////////////////////////////////////////////////////
// C++ code automatically generated by hif2sc
// Part of HIFSuite - Version 
// Site: www.hifsuite.com - Contact: hifsuite@edalab.it
//
// HIFSuite copyright: EDALab s.r.l. - Networked Embedded Systems
// Site: www.edalab.it - Contact: info@edalab.it
// /////////////////////////////////////////////////////////////////////////


#ifndef ARB2_HH
#define ARB2_HH

#include <cmath>
#include <cstddef>
#include <stdint.h>
#include "hif_globals.hpp"
#include "muffin/FaultNode.hpp"
#include "muffin/muffin_dataTypes.hpp"

class arb2
{

public:

    muffin::FaultNode hif_fault_node;
    bool req2_old;
    bool req1_old;
    bool rst_old;
    bool clk_old;
    struct arb2_iostruct{
        bool clk;
        bool rst;
        bool req1;
        bool req2;
        bool gnt1;
        bool gnt2;

        arb2_iostruct():
            clk(false),
            rst(false),
            req1(false),
            req2(false),
            gnt1(false),
            gnt2(false)
        {}

        arb2_iostruct( const bool clk_0, const bool rst_0, const bool req1_0, const
             bool req2_0, const bool gnt1_0, const bool gnt2_0 ):
            clk(clk_0),
            rst(rst_0),
            req1(req1_0),
            req2(req2_0),
            gnt1(gnt1_0),
            gnt2(gnt2_0)
        {}

        ~arb2_iostruct()
        {}

        bool operator == (const arb2_iostruct & other) const
        {
            if (clk != other.clk) return false;
            if (rst != other.rst) return false;
            if (req1 != other.req1) return false;
            if (req2 != other.req2) return false;
            if (gnt1 != other.gnt1) return false;
            if (gnt2 != other.gnt2) return false;
            return true;
        }
    };
    arb2_iostruct hif_a2t_data;
    bool gnt1_out_sig;
    bool gnt1_out_sig_sig_var;
    bool state;
    arb2();


    ~arb2();


    bool gnt1_out_sig_new;
    bool state_new;
    bool process_in_queue;
    bool flag_process_executed;
    bool flag_pos_clk;
    bool flag_pos_rst;
    bool flag_process_0_executed;
    bool flag_state;
    bool flag_req1;
    bool flag_req2;
    bool flag_gnt1_out_sig;

    void process();


    void process_0();


    void gnt1_update_process();


    void update_input_queue( bool synch_phase = true );


    void update_event_queue();


    void flag_elaboration();


    void synch_elaboration();


    void simulate( arb2_iostruct * io_exchange, int32_t & cycles_number );


    void start_of_simulation();


    void initialize();


    void finalize();


private:

    arb2( const arb2 & );
    const arb2& operator= ( const arb2 & );


};


#endif

