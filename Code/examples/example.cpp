


#include <chsm.h>

#include <iostream>
using namespace std;

class light_data : public CHSM::machine {
public: 
    light_data(CHSM_MACHINE_ARGS) : CHSM::machine(CHSM_MACHINE_INIT), flag_(1) { }
    
    int flag() const{
        return flag_;
    }

protected:
    int flag_;
};

#ifndef light_chsmc_H
#define light_chsmc_H

#include <chsm.h>
namespace CHSM_ns_alias = CHSM_NS;

///// CHSM: user declarations

///// CHSM: machine calss declaration
class light_machine : public light_data {
public:
    light_machine();
    ~light_machine();

    class state_root : public CHSM_ns_alias::cluster {
    public:
        state_root(CHSM_STATE_ARGS, bool chsm_history_);
    private:
        static state::id const children_[];
    }root;

    CHSM_ns_alias::state on;
    CHSM_ns_alias::state off;

    //evnet

private:
    static CHSM_ns_alias::transition::id const turn_on_transition[];
public:
    class turn_on_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;
    public:
        struct param_block : base_param_block {
            #line 24 "example.chsmc"
            unsigned value;
            param_block(CHSM_ns_alias::event const&, unsigned);
        protected:
            virtual ~param_block();
            bool precondition() const;
        };
        param_block* operator->() const{
            return static_cast<param_block*>(param_block_);
        }
        void operator()(unsigned);
    protected:
        turn_on_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT) { }
        friend class light_machine;
    }turn_on;

private:
    static CHSM_ns_alias::transition::id const turn_off_transition[];
public:
    class turn_off_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;
    public:
        struct param_block : base_param_block {
            #line 19 "example.chsmc"
            unsigned value;
            param_block(CHSM_ns_alias::event const&, unsigned);
        protected:
            virtual ~param_block();
            bool precondition() const;
        };

        param_block* operator->() const {
            return static_cast<param_block*>(param_block_);
        }
        void operator()(unsigned);
    protected:
        turn_off_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT) { }
        friend class light_machine;
    }turn_off;

    

};