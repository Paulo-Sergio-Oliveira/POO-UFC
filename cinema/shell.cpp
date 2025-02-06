#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

template<class CONTAINER, class FUNC>
string map_join(const CONTAINER& c, FUNC f, string sep) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

class Client {
    string id;
    int phone;

public:

    Client(string id, int phone):id(id), phone(phone) {}

    int getPhone() {
        return this->phone;
    }

    void setPhone(int p) {
        this->phone = p;
    }

    string getId() {
        return this->id;
    }

    void setId(string i) {
        this->id = i;
    }

    string str() {
        stringstream ss;
        ss << id << ":" << phone;
        return ss.str();
    }
};

class Theater {
    vector<shared_ptr<Client>> seats;

    int search(string name) {
        for(size_t i = 0; i < seats.size(); i++) {
            if(seats[i] !=  nullptr && seats[i]->getId() == name) {
                return (int) i;
            }
        }
        return (int) seats.size();
    }

    bool verifyIndex(int i) {
        if (seats[i] != nullptr) {
            return false;
        }
        return true;
    }

public:

    Theater(int number = 0) {
        seats = vector<shared_ptr<Client>>(number, nullptr);
    }

    void reserve(string id, int phone, int i) {
        if(i  > (int) seats.size()) {
            cout << "fail: cadeira nao existe" << endl;
            return;
        }

        if(!verifyIndex(i)) {
            cout << "fail: cadeira ja esta ocupada" << endl;
            return;
        }
        
        if(search(id) != (int) seats.size()) {
            cout << "fail: cliente ja esta no cinema" << endl;
            return;
        }
        
        seats[i] = make_shared<Client>(id, phone);
    }

    void cancel(string id) {
        if(search(id) != (int) seats.size()) {
            seats[search(id)] = nullptr;
            return;
        }
        
        cout << "fail: cliente nao esta no cinema" << endl;
    }

    string str() {
        stringstream ss;
        ss << "[";
        for(size_t i = 0; i < seats.size(); i++) {
            ss << (i == 0 ? "" : " ");
            ss << (seats[i] == nullptr ? "-" : seats[i]->str());
        }
        ss << "]" << endl;
        return ss.str();
    }
};

int main() {
    Theater theater;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;    
        } else if (cmd == "show") {
            cout << theater.str();
        } else if (cmd == "init") {
            int qtd;
            ss >> qtd;
            theater = Theater(qtd);
        } else if (cmd == "reserve") {
            string id;
            int index, phone;
            ss >> id >> phone >> index;
            theater.reserve(id, phone, index);
        } else if (cmd == "cancel") {
            string id;
            ss >> id;
            theater.cancel(id);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
