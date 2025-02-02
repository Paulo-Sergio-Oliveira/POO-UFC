#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

class Person {
    string name;
    int money;

    public:
        
        Person(string name, int money): name(name), money(money) {}

        int getMoney() {
            return this->money;
        }

        void setMoney(int m) {
            this->money = m;
        }

        string str() {
            stringstream ss;
            ss << name << ":" << money;
            return ss.str();
        }
};

class Moto {
    int cost;
    shared_ptr<Person> passenger;
    shared_ptr<Person> driver;

    public:

        Moto(int cost, shared_ptr<Person> pass, shared_ptr<Person> driver):
        cost(cost), passenger(pass), driver(driver) {}

        string str() {
            stringstream ss;
            ss << "Cost: " << this->cost 
            << ", Driver: " << (this->driver != nullptr ? this->driver->str() : "None")
            << ", Passenger: " << (this->passenger != nullptr ? this->passenger->str() : "None") << endl;
            return ss.str();
        }

        void setDriver(string name, int money) {
            if(this->driver == nullptr) {
                this->driver = make_shared<Person>(name, money);
                return;
            }
        }

        void setPass(string name, int money) {
            if(this->passenger == nullptr) {
                this->passenger = make_shared<Person>(name, money);
                return;
            }
        }

        void drive(int distance) {
            if(this->driver != nullptr) {
                this->cost += distance;
                return;
            }
        }

        void leavePass() {
            if(this->passenger != nullptr) {
                this->driver->setMoney(this->driver->getMoney() + this->cost);
                this->passenger->setMoney(this->passenger->getMoney() - this->cost);
                this->cost = 0;

                if(this->passenger->getMoney() < 0) {
                    cout << "fail: Passenger does not have enough money" << endl;
                    this->passenger->setMoney(0);
                }

                cout << this->passenger->str() << " left" << endl;
                this->passenger = nullptr;
                return;
            }
        }
};

int main() {
    
    Moto moto = Moto(0, nullptr, nullptr);

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } 
        else if (cmd == "show") { 
            cout << moto.str();
        }
        else if (cmd == "setDriver") { 
            string name;
            int money;
            ss >> name >> money;
            moto.setDriver(name, money);
        }
        else if (cmd == "setPass") { 
            string name;
            int money;
            ss >> name >> money;
            moto.setPass(name, money);
        }
        else if (cmd == "drive") { 
            int distance;
            ss >> distance;
            moto.drive(distance);
        }
        else if (cmd == "leavePass") { 
            moto.leavePass();
        }
        else {
            cout << "fail: command not found\n";
        }
    }
}
