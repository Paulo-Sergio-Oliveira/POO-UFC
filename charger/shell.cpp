#include <iostream>
#include <memory>
#include <utility>
#include "fn.hpp"
#include "student.hpp"

class Adapter {
    Notebook notebook;
public:
    void show() {
        std::cout << notebook.str() << '\n';
    }

    void turn_on() {
        notebook.turn_on();
    }

    void turn_off() {
        notebook.turn_off();
    }

    void set_charger(int power) {
        notebook.set_charger(power);
    }
    void rm_charger() {
        notebook.rm_charger();
    }
    void set_battery(int capacity) {
        notebook.set_battery(capacity);
    }

    void rm_battery() {
        notebook.rm_battery();
    }

    void use(int minutes) {
        notebook.use(minutes);
    }
};

int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end")         { break;                                   }
        else if (args[0] == "show")        { adp.show();                              }
        else if (args[0] == "turn_on")     { adp.turn_on();                           }
        else if (args[0] == "turn_off")    { adp.turn_off();                          }
        else if (args[0] == "use")         { adp.use(+args[1]);                       }
        else if (args[0] == "set_charger") { adp.set_charger(+args[1]);               }
        else if (args[0] == "rm_charger")  { adp.rm_charger();                        }
        else if (args[0] == "set_battery") { adp.set_battery(+args[1]);               }
        else if (args[0] == "rm_battery")  { adp.rm_battery();                        }
        else                               { std::cout << "fail: comando inválido\n"; }
    }    
}
