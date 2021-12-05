

/**
 * @file
 * Complete program to implement a BX_3000A.
 * 
 * @note 
 */

 #include <chsm.h>

 #include <cctype>
 #include <iostream>
 #include <iomanip>

 using namespace std;

 /**
 * Contains additional data and member functions for a microwave CHSM.
 */
class bx_data : pulbic CHSM::machine {
public:
    bx_data(CHSM_STATE_ARGS) : CHSM::machine(CHSM_MACHINE_INIT) { }

    void positive_run();
    void positive_stop();
    void reverse_run();
    void reverse_stop();
    void all_stop();

    void wipeCounter();
    void errCounter();

protected:
    unsigned int wipe_cnt;
    unsigned int stop_cnt;
};

void bx_data::positive_run() {

}

void bx_data::reverse_run() {

}

void bx_data::all_stop() {

}

void bx_data::wipeCounter() {
    wipe_cnt += 1;
}

void bx_data::errCounter() {
    err_cnt += 1;
}


///// CHSM: <<CHSM 5.0>>

#include <chsm.h>
namespace CHSM_ns_alias = CHSM_NS;

///// CHSM: user declarations

#line 138 "BX_3000A"

///// CHSM: machine class declarations

class BX_3000A : public bx_data {
public:
    BX_3000A();
    ~BX_3000A();

// state
    class state_root : public CHSM_ns_alias::cluster {                      // id = -1
    public:
        state_root(CHSM_STATE_ARGS, bool chsm_history_);
    private:
        static state::id const children_[];
    } root;

    class state_components : public CHSM_ns_alias::set {                    // id = 0
    public:
        CHSM_ns_alias::state idle;                                          // id = 1

        class state_operational : public CHSM_ns_alias::cluster {           // id = 2
        public:
            CHSM_ns_alias::state acceleration;                               // id = 3
            CHSM_ns_alias::state positive_turn;                             // id = 4
            CHSM_ns_alias::state reverse_turn;                              // id = 5
            CHSM_ns_alias::state deceleration;                              // id = 6

            state_operational(CHSM_STATE_ARGS, bool chsm_history_);
        private:
            static state::id const children_[];
        } operational;

        class state_error : public CHSM_ns_alias::cluster {                 // id = 7
        public:
            CHSM_ns_alias::state err_wrong_input;                           // id = 8
            CHSM_ns_alias::state err_high_volt;                             // id = 9
            CHSM_ns_alias::state err_emerg;                                 // id = 10

            state_error(CHSM_STATE_ARGS, bool chsm_history_);
        private:
            static state::id const children_[];
        } error;
    
        state_components(CHSM_STATE_ARGS);
    private:
        static state::id const children_[];
    } components;

// event
private:
	static CHSM_ns_alias::transition::id const wrong_input_transitions[];
public:
	class wrong_input_event : public CHSM_ns_alias::event {
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
		wrong_input_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} wrong_input;
	alignas(wrong_input_event::param_block) char wrong_input_param_block[ sizeof(wrong_input_event::param_block) ];        

private:
	static CHSM_ns_alias::transition::id const pos_accel_transitions[];
public:
	class pos_accel_event : public CHSM_ns_alias::event {
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
		pos_accel_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} pos_accel;
	alignas(pos_accel_event::param_block) char pos_accel_param_block[ sizeof(pos_accel_event::param_block) ];

private:
	static CHSM_ns_alias::transition::id const rev_accel_transitions[];
public:
	class rev_accel_event : public CHSM_ns_alias::event {
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
		rev_accel_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} rev_accel;
	alignas(rev_accel_event::param_block) char rev_accel_param_block[ sizeof(rev_accel_event::param_block) ];

private:
	static CHSM_ns_alias::transition::id const positive_transitions[];
public:
	class positive : public CHSM_ns_alias::event {
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
		positive_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} positive;
	alignas(positive_event::param_block) char positive_param_block[ sizeof(positive_event::param_block) ];        

private:
	static CHSM_ns_alias::transition::id const reverse_transitions[];
public:
	class reverse_event : public CHSM_ns_alias::event {
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
		reverse_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} reverse;
	alignas(reverse_event::param_block) char reverse_param_block[ sizeof(reverse_event::param_block) ]; 
    
private:
	static CHSM_ns_alias::transition::id const pos_decel_transitions[];
public:
	class pos_decel_event : public CHSM_ns_alias::event {
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
		pos_decel_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} pos_decel;
	alignas(pos_decel_event::param_block) char pos_decel_param_block[ sizeof(pos_decel_event::param_block) ];

private:
	static CHSM_ns_alias::transition::id const rev_decel_transitions[];
public:
	class rev_decel_event : public CHSM_ns_alias::event {
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
		rev_decel_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} rev_decel;
	alignas(rev_decel_event::param_block) char rev_decel_param_block[ sizeof(rev_decel_event::param_block) ];

private:
	static CHSM_ns_alias::transition::id const stop_transitions[];
public:
	class stop_event : public CHSM_ns_alias::event {
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
		stop_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} stop;
	alignas(stop_event::param_block) char stop_param_block[ sizeof(stop_event::param_block) ];

private:
	static CHSM_ns_alias::transition::id const high_volt_transitions[];
public:
	class high_volt_event : public CHSM_ns_alias::event {
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
		high_volt_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} high_volt;
	alignas(high_volt_event::param_block) char high_volt_param_block[ sizeof(high_volt_event::param_block) ];                 

private:
	static CHSM_ns_alias::transition::id const emerg_stop_transitions[];
public:
	class emerg_stop_event : public CHSM_ns_alias::event {
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
		emerg_stop_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} emerg_stop;
	alignas(emerg_stop_event::param_block) char emerg_stop_param_block[ sizeof(emerg_stop_event::param_block) ];

private:
	static CHSM_ns_alias::transition::id const finish_transitions[];
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
		finish_event( CHSM_EVENT_ARGS ) : base_event( CHSM_EVENT_INIT ) { }
		friend class BX_3000A;
	} finish;
	alignas(finish_event::param_block) char finish_param_block[ sizeof(finish_event::param_block) ];                    

// transition conditions

// transition targets

// transition actions
	void A1( CHSM_ns_alias::event const& );                                                           
	void A2( CHSM_ns_alias::event const& );
    void A3( CHSM_ns_alias::event const& );
    void A4( CHSM_ns_alias::event const& );                                                                                                                                                       

// enter/exit actions
    void EAM10components5error15err_wrong_input( CHSM_ns_alias::state const&, CHSM_ns_alias::event const& );
    void EAM10components5error13err_high_volt( CHSM_ns_alias::state const&, CHSM_ns_alias::event const& );
    void EAM10components5error9err_emerg( CHSM_ns_alias::state const&, CHSM_ns_alias::event const& );
    void EAM10components5error( CHSM_ns_alias::state const&, CHSM_ns_alias::event const& );
private:
	CHSM_ns_alias::state *state_[12];
	static CHSM_ns_alias::transition const transition_[];
	CHSM_ns_alias::event const *taken_[11];
	CHSM_ns_alias::state *target_[11];
};

///// CHSM: THE END
#endif
#include <new>

///// CHSM: state definitions
CHSM_ns_alias::state::id const BX_3000A::state_root::children_[] = {
    0, -1
};
BX_3000A::state_root::state_root(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_)
{
}

CHSM_ns_alias::state::id const BX_3000A::state_components::children_[] = {
    1, 2, 7, -1
};
BX_3000A::state_components::state_components(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::set(CHSM_STATE_INIT, children_),
    idle(chsm_machine_, "components.idle", this, nullptr, nullptr, nullptr, nullptr ),
    operational(chsm_machine_, "components.operational", this, nullptr, nullptr, nullptr, nullptr ,true ),
    error(chsm_machine_, "components.error", static_cast<CHSM_ns_alias::state::action>(&EAM10components5error), nullptr, nullptr, nullptr ,true )
{
}

CHSM_ns_alias::state::id const BX_3000A::state_components::state_operational::children_[] = {
    3, 4, 5, 6, -1
}
BX_3000A::state_components::state_operational::state_operational(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_),
    acceleration(chsm_machine_, "components.operational.acceleration", this, nullptr, nullptr, nullptr, nullptr ),
    positive_turn(chsm_machine_, "components.operational.positive_turn", this nullptr, nullptr, nullptr, nullptr ),
    reverse_turn(chsm_machine_, "components.operational.reverse_turn", this, nullptr, nullptr, nullptr, nullptr ),
    deceleration(chsm_machine_, "components.operational.deceleration", this, nullptr, nullptr, nullptr, nullptr )
{
}

CHSM_ns_alias::state::id const BX_3000A::state_components::state_error::children_[] = {
    8, 9, 10, -1
}
BX_3000A::state_components::state_error::state_error(CHSM_STATE_ARGS, bool chsm_history_) :
    CHSM_ns_alias::cluster(CHSM_STATE_INIT, children_, chsm_history_),
    err_wrong_input(chsm_machine_, "components.error.err_wrong_input", this, static_cast<CHSM_ns_alias::state::action>(&EAM10components5error15err_wrong_input), nullptr, nullptr, nullptr ),
    err_high_volt(chsm_machine_, "components.error.err_high_volt", this, static_cast<CHSM_ns_alias::state::action>(&EAM10components5error13err_high_volt), nullptr, nullptr, nullptr ),
    err_emerg(chsm_machine_, "components.error.err_emerg", this, static_cast<CHSM_ns_alias::state::action>(&EAM10components5error9err_emerg), nullptr,nullptr, nullptr )
{
}

///// CHSM: event definitions
CHSM_ns_alias::transtion::id const BX_3000A::wrong_input_transitions[] = {
    0, -1
};
BX_3000A::wrong_input_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::pos_accel_transitions[] = {
    1, -1
};
BX_3000A::pos_accel_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::rev_accel_transitions[] = {
    2, -1
};
BX_3000A::rev_accel_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::high_volt_transitions[] = {
    3, -1
};
BX_3000A::high_volt_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::emerg_stop_transitions[] = {
    4, -1
};
BX_3000A::emerg_stop_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::positive_transitions[] = {
    5, -1
};
BX_3000A::positive_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::reverse_transitions[] = {
    6, -1
};
BX_3000A::reverse_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::pos_decel_transitions[] = {
    7, -1
};
BX_3000A::pos_decel_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::rev_decel_transitions[] = {
    8, -1
};
BX_3000A::rev_decel_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::stop_transitions[] = {
    9, -1
};
BX_3000A::stop_event::param_block::~param_block() { }

CHSM_ns_alias::transition::id const BX_3000A::finish_transitions[] = {
    10, -1
};
BX_3000A::finish_event::param_block::~param_block() { }

///// CHSM: Transitions
CHSM_ns_alias::transition const BX_3000A::transition_[] = {
    { nullptr, 1, 3, nullptr, static_cast<CHSM_ns_alias::transition::action>(&BX_3000A::A1) },
    { nullptr, 1, 3, nullptr, static_cast<CHSM_ns_alias::transition::action>(&BX_3000A::A2) },
    { nullptr, 1, 8, nullptr, nullptr },
    { nullptr, 6, 1, nullptr, nullptr },
    { nullptr, 2, 9, nullptr, nullptr },
    { nullptr, 2, 10, nullptr, nullptr },
    { nullptr, 3, 4, nullptr, nullptr },
    { nullptr, 3, 5, nullptr, nullptr },
    { nullptr, 4, 6, nullptr, static_cast<CHSM_ns_alias::transition::action>(&BX_3000A::A3) },
    { nullptr, 5, 6, nullptr, static_cast<CHSM_ns_alias::transition::action>(&BX_3000A::A4) },
    { nullptr, 7, 1 nullptr, nullptr }
};

///// CHSM: CHSM Constructor definition
BX_3000A::BX_3000A() :
	bx_data ( state_, root, transition_, taken_, target_, 11 ),
    root( *this, "root", nullptr, nullptr, nullptr, nullptr, nullptr, false ),
    components( *this, "components", &root, nullptr, nullptr, nullptr, nullptr ),
    wrong_input( this, wrong_input_transitions, "wrong_input", nullptr ),
    pos_accel( this, pos_accel_transitions, "pos_accel", nullptr ),
    rev_aceel( this, rev_accel_transitions, "rev_accel", nullptr ),
    high_volt( this, high_volt_transitions, "high_volt", nullptr ),
    emerg_stop( this, emerg_stop_transitions, "emerg_stop", nullptr ),
    positive( this, positive_transitions, "positive", nullptr ),
    reverse( this, reverse_transitions, "revers", nullptr ),
    pos_decel( this, pos_decel_transitions, "pos_decel", nullptr ),
    rev_decel( this, rev_decel_transitions, "rev_decel", nullptr ),
    stop( this, stop_transitions, "stop", nullptr ),
    finish( this, finish_transitions, "finish", nullptr )
{
    state_[0] = &components;
    state_[1] = &components.idle;
    state_[2] = &components.operational;
    state_[3] = &components.operational.acceleration;
    state_[4] = &components.operational.positive_turn;
    state_[5] = &components.operational.reverse_turn;
    state_[6] = &components.operational.deceleration;
    state_[7] = &components.error;
    state_[8] = &components.error.err_wrong_input;
    state_[9] = &components.error.err_high_volt;
    state_[10] = &components.error.err_emerg;
    state_[11] = nullptr;
}

BX_3000A::~BX_3000A() { }

// user-code
void BX_3000A::A1( CHSM_ns_alias::event const &event ) {
    (void)event;
#line 88 "BX_3000A.chsmc"
        positive_run();
}

void BX_3000A::A2( CHSM_ns_alias::event const &event ) {
    (void)event;
#line 92 "BX_3000A.chsmc"
        reverse_run();
}

void BX_3000A::A3( CHSM_ns_alias::event const &event ) {
    (void)event;
#line 110 "BX_3000A.chsmc"
        positive_stop();
}

void BX_3000A::A4( CHSM_ns_alias::event const &event ) {
    (void)event;
#line 117 "BX_3000A.chsmc"
        reverse_stop();
}

void BX_3000A::EAM10components5error( CHSM_ns_alias::state const &chsm_state_, CHSM_ns_alias::event const &event ) {
    (void)event;
#line 127 "BX_3000A.chsmc"
    CHSM_ns_alias::cluster const &state = dynamic_cast<CHSM_ns_alias::cluster const&>(chsm_state_);
    (void)state;
        errCounter();
}

void BX_3000A::EAM10components5error13err_high_volt( CHSM_ns_alias::state const &chsm_state_, CHSM_ns_alias::event const &event ) {
    (void)event;
#line 133 "BX_3000A.chsmc"
    CHSM_ns_alias::state const &state = dynamic_cast<CHSM_ns_alias::state const&>(chsm_state_);
    (void)state;
        all_stop();
}

void BX_3000A::EAM10components5error9err_emerg( CHSM_ns_alias::state const &chsm_state_, CHSM_ns_alias::event const &event ) {
    (void)event;
#line 139 "BX_3000A.chsmc"
    CHSM_ns_alias::state const &state = dynamic_cast<CHSM_ns_alias::state const&>(chsm_state_);
    (void)state;
        all_stop();
}

void BX_3000A::EAM10components5error15err_wrong_input( CHSM_ns_alias::state const &chsm_state_, CHSM_ns_alias::event const &event ) {
    (void)event;
#line 145 "BX_3000A.chsmc"
    CHSM_ns_alias::state const &state = dynamic_cast<CHSM_ns_alias::state const&>(chsm_state_);
    (void)state;
        all_stop();
}

#line 152 "BX_3000A.chsmc"

///// CHSM: THE END

int main() {
    cout.fiil( '0' );
    BX_3000A bx;
    bx.debug( CHSM::machine::DEBUG_ALL );
    bx.enter();

    while( !cin.eof() ) {
        bx.dump_state();

        cout << "\nENTER: (P)os_accel (R)ev_accel (H)igh_volt (E)merg_stop "
                ""
        char ch; 
        cin >> ch;
        
        switch(toupper(ch)){
            case 'P': bx.pos_accel(); break;
            case 'R': bx.rev_accel(); break;
            case 'H': bx.high_volt(); break;
            case 'E': bx.emerg_stop(); break;
            case 'O': bx.positive(); break;
            case 'V': bx.reverse(); break;
            case 'C': bx.pos_decel(); break; 
            case "D": bx.rev_decel(); break;
            case 'F': bx.finish(); break;
            case 'S': bx.stop(); break;
            default : bx.wrong_input(); break;
        }
    }

    return 0;
    
}