#include "fn.hpp"
using namespace std;

class Charger {
    int power;

    public:

        Charger(int power): power(power) {}

        int getPower() {
            return this->power;
        }

        string str() {
            return fn::format("{}W", this->power);
        }
};

class Battery {
    int capacity;
    int charge;

    public:

        Battery(int capacity): capacity(capacity) {
            this->charge = capacity;
        }

        int getCharge() {
            return this->charge;
        }

        int getCapacity() {
            return this->capacity;
        }

        void setCharge(int c) {
            this->charge = c;
        }
        string str() {
            return fn::format("{}/{}", this->charge, this->capacity);
        }
};

class Notebook {
    shared_ptr<Charger> charger;
    shared_ptr<Battery> battery;
    bool on;
    int usage = 0;

    public: 

        Notebook(shared_ptr<Charger> charger = nullptr, shared_ptr<Battery> battery = nullptr, bool on = false):
        charger(charger), battery(battery), on(on) {}

        string str() {
            return fn::format("Notebook: {}{}",
            (this->on ? "ligado por " + to_string(this->usage) + " min" : "desligado"),
            (this->charger != nullptr ? ", Carregador " + this->charger->str() : ""),
            (this->battery != nullptr ? ", Bateria " + this->battery->str() : ""));
        }

        void turn_on() {
            
            if(this->charger == nullptr && (this->battery == nullptr || this->battery->getCharge() == 0)) {
                cout << "fail: não foi possível ligar" << endl;
                return;
            }

            on = true;
        }

        void turn_off() {
            on = false;
        }

        void use(int minutes) {
            if(!on) {
                cout << "fail: desligado" << endl;
                return;
            }

            if(this->battery != nullptr) {
                if(this->charger == nullptr) {
                    this->battery->setCharge(this->battery->getCharge() - minutes);
                } else {
                    this->battery->setCharge(this->battery->getCharge() + (this->charger->getPower() * minutes));
                }

                if(this->battery->getCharge() > this->battery->getCapacity()) {
                    this->battery->setCharge(this->battery->getCapacity());
                }

                if(this->battery->getCharge() <= 0) {
                    cout << "fail: descarregou" << endl;
                    this->battery->setCharge(0);
                    this->on = false;
                    return;
                }
            }
            
            
            this->usage += minutes;
        }

        void set_charger(int power) {
            if(this->charger != nullptr) {
                cout << "fail: carregador já conectado" << endl;
                return;
            }

            this->charger = make_shared<Charger>(power);
        }

        void set_battery(int capacity) {
            this->battery = make_shared<Battery>(capacity);
        }

        void rm_charger() {
            if(this->charger == nullptr) {
                cout << "fail: Sem carregador" << endl;
                return;
            }

            if(this->battery == nullptr) {
                this->on = false;
            }

            cout << "Removido " + this->charger->str() << endl;
            this->charger = nullptr;
        }

        void rm_battery() {
            if(this->battery == nullptr) {
                cout << "fail: Sem bateria" << endl;
                return;
            }

            if(this->charger == nullptr) {
                this->on = false;
            }

            cout << "Removido " + this->battery->str() << endl;
            this->battery = nullptr;
        }
};