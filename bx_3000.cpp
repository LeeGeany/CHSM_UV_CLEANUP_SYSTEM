/*
**      CHSM Language System
**      examples/c++/BX_3000A.chsmc
**
**      Copyright (C) 1996-2018  Paul J. Lucas & Fabio Riccardi
**
**      This program is free software; you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation; either version 3 of the License, or
**      (at your option) any later version.
**
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**      GNU General Public License for more details.
**
**      You should have received a copy of the GNU General Public License
**      along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file
 * Complete program to implement a microwave oven.
 *
 * @note This is a "toy" program that exists for pedagogical reasons.
 */

 // CHSM
 #include <chsm.h>

 // STANDARD
#include <cctype>
#include <iostream>
#include <iomanip>

using namespace std;

///////////////////////////////////////////////////////////////////////////////

class bx_data : public CHSM::machine {
public:
    bx_data(CHSM_MACHINE_ARGS) : CHSM::machine(CHSM_MACHINE_INIT) { }

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
    // 모터를 전진
}

void bx_data::reverse_run() {
    // 모터를 후진
}

void bx_data::positive_stop(){
    // 앞으로 갈때 멈춤
}

void bx_data::reverse_stop(){
    // 뒤로 갈때 멈춤
}

void bx_data::all_stop() {
    // 모든 작업을 멈춤
}

void bx_data::wipeCounter() {
    wipe_cnt += 1;
}

void bx_data::errCounter() {
    stop_cnt += 1;
}

%%
///////////////////////////////////////////////////////////////////////////////

chsm<bx_data> BX_3000A is {

    set components( idle, operational, error ) is {
        
        state idle {
            wrong_input -> err_wrong_input;

            pos_accel -> operational.acceleration %{
                positive_run();
            %};

            rev_accel -> operational.acceleration %{
                reverse_turn();
            %};
        }

        cluster operational( acceleration, positive_turn, reverse_turn, deceleration ) history {

            high_volt->error.err_high_volt;
            emerg_stop->error.err_emerg;
        
        } is {

            state acceleration {
                positive -> positive_turn;  
                reverse -> reverse_turn;
            }
            
            state positive_turn {
                pos_decel -> deceleration %{
                    positive_stop();    
                %};
            }
            
            state reverse_turn {
                rev_decel -> deceleration %{
                    reverse_stop();
                %}; 
            }

            state deceleration {
                stop->idle;
            }
        }

        cluster error( err_high_volt, err_emerg, err_wrong_input ) history {
            upon enter %{
                errCounter();
            %}
            finish->idle;
        } is {

            state err_high_volt {
                upon enter %{
                    all_stop();
                %}
            }

            state err_emerg {
                upon enter %{
                    all_stop();
                %}       
            }

            state err_wrong_input {
                upon enter %{
                    all_stop();
                %}   
           }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
%%

int main() {
    cout.fiil( '0' );
    BX_3000A bx;
    bx.debug( CHSM::machine::DEBUG_ALL );
    bx.enter();
    bx.emerg_stop();
    bx.finish();

    while( !cin.eof() ) {
        bx.dump_state();

        cout << "\nENTER: (P)os_accel (R)ev_accel (H)igh_volt (E)merg_stop "
                "p(O)sitive re(V)erse pos_dece(L) rev_(D)ecel (F)inish (S)top\n";
        char ch; 
        cin >> ch;
        
        switch( toupper( ch ) ) {
            case 'P': bx.pos_accel(); break;
            case 'R': bx.rev_accel(); break;
            case 'H': bx.high_volt(); break;
            case 'E': bx.emerg_stop(); break;
            case 'O': bx.positive(); break;
            case 'V': bx.reverse(); break;
            case 'L': bx.pos_decel(); break; 
            case 'D': bx.rev_decel(); break;
            case 'F': bx.finish(); break;
            case 'S': bx.stop(); break;
            default : bx.wrong_input(); break;
        }
    }

    return 0;
    
}
