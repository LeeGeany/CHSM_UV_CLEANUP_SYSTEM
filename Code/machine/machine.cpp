// CHSM
#include <chsm.h>

// STANDARD
#include <iostream>
#include <cctype>
#include <iomanip>

// THREAD
#include <future>
#include <thread>

// STL
#include <vector>

// DEFINE
#define UV_SENSOR_FUNC              true
#define UV_SENSOR_MAL_FUNC          false
#define CT_SENSOR_FUNC_L            true
#define CT_SENSOR_MAL_FUNC_L        false
#define CT_SENSOR_FUNC_R            true
#define CT_SENSOR_MAL_FUNC_R        false

#define MAX_MOTOR_RANGE             10000

using namespace std;

class machine_data : public CHSM:machine { 
public:
    machine_data(CHSM_MACHINE_ARGS) : CHSM:machine(CHSM_MACHINE_INIT),
    distance_( 0 ), wipe_position_( 0 ),  { }

    // operate function
    void initialize();
    void oper_motor(int distance);
    void all_stop();
    
    // get data from sensor
    bool get_UV_Data();
    bool get_Left_CT_Data();
    bool get_Right_CT_Data();

protected:
    unsigned int distance_;
    unsigned int wipe_position_;
    unsigned bool old_uv_sensor_ uv_sensor_;
    unsigned int cnt_round;
    unsigned int cnt_wipe;
};

void machine_data::initialize(){
    /* initialize the system */
}

void machine_data::oper_motor(int distance){
    /* operate the motor*/
}

void machine_data::all_stop(){
    /* all stop (all stop) */
}

bool machine_data::get_UV_Data(promise<bool>* p){
    
    p->get_value(UV_SENSOR_FUNC);
}

bool machine_data::get_Left_CT_Data(promise<bool>* p){

    p->get_value(CT_SENSOR_FUNC_L)
}

bool machine_data::get_Right_CT_Data(promise<bool>* p){

    p->get_value(CT_SENSOR_FUNC_R)
}

#ifndef machine_chsmc_H
#define machine_chsmc_H

///// CHSM: <<CHSM 5.0>>

#include <chsm.h>
namespace CHSM_ns_alias = CHSM_NS;

///// CHSM: user declarations

#line 666 "machine.chsmc"

///// CHSM: machine class declaration

class machine : public mw_data {
public:
    machine();
    ~machine();

    // states
    class state_root : public CHSM_ns_alias:: cluster { // id = -1
    public:
        state_root(CHSM_STATE_ARGS, bool chsm_history_);
    private:
        static state:id const children_[];
    } root;

    class state_components : public CHSM_ns_alias::set { // id = 0
    public:
        class state_operational : public CHSM_ns_alias::cluster { // id = 1
        public:
            CHSM_ns_alias::state idle; // id = 2
            CHSM_ns_alias::state replacement; // id = 3

            state_operational(CHSM_STATE_ARGS, bool chsm_history_);
        private:
            static state::id const children_[];
        } operational;

        class state_action : public CHSM_ns_alias::cluster { // id = 4
        public:
            class state_auto_wipe : public CHSM_ns_alias::cluster { // id = 5
            public:
                CHSM_ns_alias::state a_stop;    // id = 6
                CHSM_ns_alias::state a_right;   // id = 7
                CHSM_ns_alias::state a_left;    // id = 8

                state_auto_wipe(CHSM_STATE_ARGS, bool chsm_history_);
            private:
                state state::id const children_[];
            } auto_wipe;

            class state_manual_wipe : public CHSM_ns_alias::cluster { // id = 9
            public:
                CHSM_ns_alias::state m_stop;    // id = 10
                CHSM_ns_alias::state m_right;    // id = 11
                CHSM_ns_alias::state m_left;   // id = 12

                state_manual_wipe(CHSM_STATE_ARGS, bool chsm_history_);
            private:
                static state::id const children_[];
            } manual_wipe;

            state_action(CHSM_STATE_ARGS, bool chsm_history_);
        private:
            static state::id const children_[];
        } action;

        CHSM_ns_alias::state emergency  // id = 13

        state_components(CHSM_STATE_ARGS);
    private:
        static state::id const children_[];
    } components;

// event
private:
    static CHSM_ns_alias::transition::id const go_auto_wipe_transition[];
public:
    class go_auto_wipe_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_auto_wipe_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_auto_wipe;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const go_manual_wipe_transition[];
public:
    class go_manual_wipe_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_manual_wipe_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_manual_wipe;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const go_replacement_transition[];
public:
    class go_replacement_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_replacement_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_replacement;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const go_oper_transition[];
public:
    class go_oper_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_oper_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_oper;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const go_stop_transition[];
public:
    class go_stop_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_stop_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_stop;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const go_left_transition[];
public:
    class go_left_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_left_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_left;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const go_right_transition[];
public:
    class go_right_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        go_right_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } go_right;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const finish_transition[];
public:
    class finish_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        finish_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } finish;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

private:
    static CHSM_ns_alias::transition::id const force_stop_transition[];
public:
    class force_stop_event : public CHSM_ns_alias::event {
        typedef CHSM_ns_alias::event base_event;
        typedef base_event::param_block base_param_block;   
    public:
		struct param_block : base_param_block {
			param_block( CHSM_ns_alias::event const& event ) : 
				base_param_block( event ) { }
		protected:
			virtual ~param_block();
		};
    protected:  
        force_stop_event(CHSM_EVENT_ARGS) : base_event(CHSM_EVENT_INIT){ }
        friend class machine;
    } force_stop;    
    alignas(Open_event::param_block) char Open_param_block[ sizeof(Open_event::param_block) ];

    // transition conditions
    void c1(CHSM_ns_alias::event const&);    // go_left[get_Left_CT_Data()]->a_left;
    void c2(CHSM_ns_alias::event const&);    // go_right[get_Right_CT_Data()]->a_right;
    void c3(CHSM_ns_alias::event const&);    // go_manual_wipe[get_Left_CT_Data() && get_Right_CT_Data()]->manual_wipe;
    
    void c4(CHSM_ns_alias::event const&);    // go_stop[get_Right_CT_Data()]->a_stop;
    void c5(CHSM_ns_alias::event const&);    // go_manual_wipe[!get_Right_CT_Data()]->manual_wipe;

    void c6(CHSM_ns_alias::event const&);    // go_stop[get_Left_CT_Data()]->a_stop;
    void c7(CHSM_ns_alias::event const&);    // go_manual_wipe[!get_Left_CT_Data()]->manual_wipe;
    
    void c8(CHSM_ns_alias::event const&);    // go_stop[get_Right_CT_Data()]->m_stop;
    void c9(CHSM_ns_alias::event const&);    // force_stop[!get_Right_CT_Data()]->emergency;
    
    void c10(CHSM_ns_alias::event const&);   // go_stop[get_Left_CT_Data()]->m_stop;
    void c11(CHSM_ns_alias::event const&);   // force_stop[!get_Left_CT_Data()]->emergency;
    
    // transition targets

    // transition actions

    // enter/exit actions
    void EAM10components11operational4idle( CHSM_ns_alias::state const&, CHSM_ns_alias::event const& );
    void EAM10components11operational11replacement(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void EAM10components6action9auto_wipe(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void XAM10components6action9auto_wipe(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void EAM10components6action9auto_wipe7a_right(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void EAM10components6action9auto_wipe6a_left(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void EAM10components6action11manual_wipe7m_right(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void EAM10components6action11manual_wipe6m_left(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
    void EAM10components9emergency(CHSM_ns_alias::state const&, CHSM_ns_alias::event const&);
private:
/*
 *  CHSM_ns_alias::state * stete_[15];
 *  static CHSM_ns_alias::transition const transition_[];
 *  CHSM_ns_alias::event const *taken_[];
 *  CHSM_ns_alias::state *target_[];    
 */
};

///// CHSM: THE END
#endif
#include <new>

///// CHSM: state definitions
CHSM_ns_alias::state::id const machine::state_root::children_[] = {
    0, -1
};
machine::state_root::state_root(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_)
{
}

CHSM_ns_alias::id const machine::state_components::children_[] = {
    1, 4, 13, -1
};
machine::state_components:state_components(CHSM_STATE_ARGS) : 
    CHSM_ns_alias::set(CHSM_STATE_INIT, children_),
    operational(chsm_machine_, "components.operational", this, nullptr, nullptr, nullptr, nullptr, false),
    action(chsm_machine_, "components.action", this, nullptr, nullptr, nullptr, nullptr, false),
    emergency(chsm_machine_, "components.emergency", this, static_cast<CHSM_ns_alias::state::action>(&machine::EAM10components9emergency), nullptr, nullptr, nullptr)
{
}

CHSM_ns_alias::id const machine::state_components::state_operational::children_[] = {
    2, 3, -1
};
machine::state_components::state_operational::state_operational(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_),
    idle(chsm_machine_, "components.operational.idle", this, static_cast<CHSM_ns_alias::state::action>(&machine::EAM10components11operational4idle), nullptr, nullptr, nullptr),
    replacement(chsm_machine_, "components.operational.replacement", this, static_cast<CHSM_ns_alias::state::action>(&machine::EAM10components11operational11replacement), nullptr, nullptr, nullptr),
{
}

CHSM_ns_alias::id const machine::state_components::state_action::children_[] = {
    5, 9, -1
};
machine::state_components::state_action::state_action(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_),
    auto_wipe(chsm_machine_, "components.action.auto_wipe", this, nullptr, nullptr, nullptr, nullptr, false),
    manual_wipe(chsm_machine_, "components.action.manual_wipe", this, nullptr, nullptr, nullptr, nullptr, false)
{
}

CHSM_ns_alias::id const machine::state_components::state_action::state_auto_wipe::children_[] = {
    8, 6, 7, -1
};
machine::state_components::state_action::state_action(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_),
    a_stop(chsm_machine_, "components.action.auto_wipe.a_stop", this, nullptr, nullptr, nullptr, nullptr),
    a_left(chsm_machine_, "components.action.auto_wipe.a_left", this, static_cast<CHSM_ns_alias::state::action>(&machine::EAM10components6action9auto_wipe6a_left), nullptr, nullptr, nullptr),
    a_right(chsm_machine_, "components.action.auto_wipe.a_right", this, static_cast<CHSM_ns_alias::state::action>(&machine::EAM10components6action9auto_wipe7a_right), nullptr, nullptr, nullptr)
{
}

CHSM_ns_alias::id const machine::state_components::state_action::state_manual_wipe::children_[] = { 
    10, 11, 12, -1
};
machine::state_components::state_action::state_action(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_),
    m_stop(chsm_machine_, "components.action.manual_wipe.m_stop", this, nullptr, nullptr, nullptr, nullpt ),
    m_left(chsm_machine_, "components.action.manual_wipe.m_left", this, static_cast<CHSM_ns_alias::state::action>(&machine::EAM10components6action11manual_wipe6m_left), nullptr, nullptr, nullptr),
    m_right(chsm_machine_, "components.action.manual_wipe.m_right", this, static_cast<CHSM_ns_alias::staet::action>(&machine::EAM10components6action11manual_wipe7m_right, nullptr, nullptr, nullptr),
{
}

///// CHSM: event definitions
CHSM_ns_alias::transition::id const machine::go_oper_transition[] = {
    5, -1
};
machine::go_oper_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::go_auto_wipe_transition[] = {
    1, -1
};
machine::go_auto_wipe_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::go_manual_wipe_transition[] = {
    2, 7, 10, 12, 14, -1
};
machine::go_manual_wipe_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::go_replacement_transition[] = {
    3, -1
};
machine::go_replacement_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::go_stop_transition[] = {
    11, 13, 17, 19, -1
};
machine::go_stop_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::go_left_transition[] = {
    8, 16, -1
};
machine::go_left_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::go_right_transition[] = {
    9, 15, -1
};
machine::go_right_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::finish_transition[] = {
    4, 21, -1
};
machine::finish_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const machine::force_stop_transition[] = {
    0, 6, 18, 20, -1
};
machine::force_stop_event::param_block::~param_block() { }

///// CHSM: transitions
CHSM_ns_alias::transition const machine::transition_[] = {
    {nullptr, 1, 13, nullptr, nullptr},
    {nullptr, 2, 3 , nullptr, nullptr},
    {nullptr, 2, 5 , nullptr, nullptr},
    {nullptr, 2, 9 , nullptr, nullptr},
    {nullptr, 3, 2 , nullptr, nullptr},
    {nullptr, 4, 1 , nullptr, nullptr},
    {nullptr, 4, 13, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c1), 6, 8, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c2), 6, 7, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c3), 6, 9, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c4), 7, 6, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c5), 7, 9, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c6), 8, 6, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c7), 8, 9, nullptr, nullptr},
    {nullptr, 10, 11, nullptr, nullptr},
    {nullptr, 10, 12, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&macihne::c8), 11, 10, nullptr, nullptr},
    {static_cast<CHSM_ns_alias::transition::condition>(&machine::c9), 11, 13, nullptr, nullptr},
    <static_cast<CHSM_ns_alias::transition::condition>(&machine::c10), 12, 10, nullptr, nullptr},
    {nullptr, 0, 0, nullptr, nullptr}
};

///// CHSM: CHSM constructor definition
machine::machine() :
    machine_data(state_, root, transition_, taken_, target_, //23),
    root(*this, "root", nullptr, nullptr, nullptr, nullptr, nullptr, fasle),
    components(*this, "components", &root, nullptr, nullptr, nullptr, nullptr),
    go_oper(this, go_oper_transition, "go_oper", nullptr),
    go_auto_wipe(this, go_auto_wipe_transition, "go_auto_wipe", nulltpr),
    go_manual_wipe(this, go_manual_wipe_transition, "go_manual_wipe", nullptr),
    go_replacement(this, go_replacement_transition, "go_replacement", nullptr),
    go_stop(this, go_stop_transition, "go_stop", nullptr),
    go_left(this, go_left_transition, "go_left", nullptr),
    go_right(this, go_right_transition, "go_right", nullptr),
    finish(this, finish_transition, "finish_transition", nullptr),
    force_stop(this, force_stop_transition, "force_stop", nullptr)    
{
    state_[0] = &components;
    state_[1] = &components.operational;
    state_[2] = &components.operational.idle;
    state_[3] = &components.operational.replacement;
    state_[4] = &components.action;
    state_[5] = &components.action.auto_wipe;
    state_[6] = &components.action.auto_wipe.a_stop;
    state_[7] = &components.action.auto_wipe.a_right;
    state_[8] = &components.action.auto_wipe.a_left;
    state_[9] = &components.action.manual_wipe;
    state_[10] = &components.action.manual_wipe.m_stop;
    state_[11] = &components.action.manual_wipe.m_right;
    state_[12] = &components.action.manual_wipe.m_left;
    state_[13] = &components.emergency;
    state_[14] = nullptr;
}

machine::~machine(){

}

// user-code
bool machine::c1(CHSM_ns_alias::event const &event){
    (void)event;
#line 144 "machine.chsmc"
    return get_Left_CT_Data();
}

bool machine::c2(CHSM_ns_alias::event const &event){
    (void)event;
#line 145 "machine.chsmc"
    return get_Right_CT_Data();
}

bool machine::c3(CHSM_ns_alias::event const &event){
    (void)event;
#line 146 "machine.chsmc"
    return get_Left_CT_Data() && get_Right_CT_Data()
}

bool machine::c4(CHSM_ns_alias::event const &event){
    (void)event;
#line 154 "machine.chsmc"
    return get_Right_CT_Data();
}

bool machine::c5(CHSM_ns_alias::event const &event){
    (void)event;
#line 155 "machine.chsmc"
    return !get_Right_CT_Data();
}

bool machine::c6(CHSM_ns_alias::event const &event){
    (void)event;
#line 164 "machine.chsmc"
    return get_Left_CT_Data();
}

bool machine::c7(CHSM_ns_alias::event const &event){
    (void)event;
#line 165 "machine.chsmc"
    return !get_Left_CT_Data()
}

bool machine::c8(CHSM_ns_alias::event const &event){
    (void)event;
#line 186 "machine.chsmc"
    return get_Right_CT_Data();
}

bool machine::c9(CHSM_ns_alias::event const &event){
    (void)event;
#line 187 "machine.chsmc"
    return !get_Right_CT_Data();
}

bool machine::c10(CHSM_ns_alias::event const &event){
    (void)event;
#line 194 "machine.chsmc"
    return get_Left_CT_Data();
}

bool machine::c11(CHSM_ns_alias:event const event){
    (void)event;
#line 195 "machine.chsmc"
    return !get_Left_CT_Data();
}

///// CHSM: THE END

int main(void)
{   
    machine mach;

#ifdef DEBUG
    mach.debug(CHSM::machine::DEBUG_ALL);
#endif

    mach.enter();
    vector<thread> threads;
    bool uv_flag, r_ct_flag, l_ct_flag;
    char itr;
    
    while(){    
        promise<bool> uv_ret;
        promise<bool> l_ct_ret;
        promise<bool> r_ct_ret;

        future<bool> uv_data = uv_ret.get_future();
        future<bool> l_ct_data = l_ct_ret.get_future();
        future<bool> r_ct_data = r_ct_ret.get_future();

        threads.push_back(thread(get_UV_Data, &uv_data));
        threads.push_back(thread(get_Left_CT_Data, &l_ct_ret));
        threads.push_back(thread(get_Right_CT_Data, & r_ct_ret));
        threads.push_back(thread(selection);

        uv_data.wait();
        l_ct_data.wait();
        r_ct_data.wait();

        uv_flag = uv_data.get();
        l_ct_flag = l_ct_data.get();
        r_ct_flag = r_ct_data.get();

        cout << "UV_CHECK : " << uv_flag << " ";
        cout << "L_CT_CHECK : " << l_ct_flag << " ";
        cout << "R_CT_CHECK : " >> r_ct_flag << "\n";
        
        if(l_ct_flag == false || r_ct_flag == false){
            mach.go_auto_wipe();
        }
    }  // while
}


