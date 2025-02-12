#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return ss.str();
}

enum Label {
    GIVE = 1,
    TAKE = 2,
    PLUS = 3
};

class Operation {
    int id;
    string name;
    Label label;
    int value;

public:
    Operation(int id, string name, Label label, int value)
    : id(id), name(name), label(label), value(value) {}

    int getId() {
        return this->id;
    }

    string getName() {
        return this->name;
    }

    Label getLabel() {
        return this->label;
    }

    string str() {
        return "";
    }

    int getValue() {
        return this->value;
    }
};

int total(map<int, Operation*> opera) {
    int soma = 0;

    for(auto e : opera){
        if(e.second->getLabel() == 1 || e.second->getLabel() == 3) soma += e.second->getValue();
        if(e.second->getLabel() == 2) soma -= e.second->getValue();
    }

    return soma;
};

class Client {
    string name;
    int limit;
    map<int, Operation*> operations;

public:
    Client(string name = "", int limit = 0) : name(name), limit(limit) {}

    string getName() {
        return this->name;
    }

    int getLimit() {
        return this->limit;
    }

    map<int, Operation*> getOperations() {
        return this->operations;
    }

    void addOperation(int id, string name, Label label, int value) {
        operations[id] = new Operation(id, name, label, value);
    }

    string str() {
        stringstream ss;
        ss << name << " " << total(operations) << "/" << limit << endl;
        for(auto e : operations) {
            ss << "id:" << e.second->getId() << " ";
            if(e.second->getLabel() == 1) ss << "give";
            if(e.second->getLabel() == 2) ss << "take";
            if(e.second->getLabel() == 3) ss << "plus";
            ss << ":" << e.second->getName() << " " << e.second->getValue() << endl;
        }
        return ss.str();
    }
};

class Shark {
    map<string, Client> alive_list;
    map<string, Client> death_list;
    map<int, Operation*> alive_oper;
    map<int, Operation*> death_oper;
    int nextOpId;

public:
    Shark() {}

    auto getClient(string name) {
        if(alive_list.find(name) == alive_list.end()) {
            throw string("fail: cliente nao existe");
        }

        return alive_list[name];
    }

    void addCli(string name, int limit) {
        if(alive_list.find(name) != alive_list.end()) {
            throw string("fail: cliente ja existe");
        }

        alive_list[name] = Client(name, limit);
    }

    void give(string name, int value) {
        if(alive_list.find(name) == alive_list.end()) {
            throw string("fail: cliente nao existe");
        }

        int all = total(alive_list[name].getOperations());
        all += value;

        if(alive_list[name].getLimit() < all) {
            throw string("fail: limite excedido");
        }

        alive_list[name].addOperation((int) alive_oper.size(), name, GIVE, value);
        alive_oper[(int) alive_oper.size()] = new Operation((int) alive_oper.size(), name, GIVE, value);
    }

    void take(string name, int value) {
        if(alive_list.find(name) == alive_list.end()) {
            throw string("fail: cliente nao existe");
        }

        alive_list[name].addOperation((int) alive_oper.size(), name, TAKE, value);
        alive_oper[(int) alive_oper.size()] = new Operation((int) alive_oper.size(), name, TAKE, value);
    }

    void plus() {
        for(auto e : alive_list) {
            int all = total(e.second.getOperations());
            int frac = ceil(all * 0.1);

            alive_list[e.first].addOperation((int) alive_oper.size(), e.first, PLUS, frac);
            alive_oper[(int) alive_oper.size()] = new Operation((int) alive_oper.size(), e.first, PLUS, frac);
        }

        for(auto it = alive_list.begin(); it != alive_list.end();) {
            int all = total(it->second.getOperations());
            if(all > it->second.getLimit()) {
                string name = it->first;
                ++it;
                kill(name);
            } else {
                ++it;
            }
        }
    }

    void kill(string name) {
        if(alive_list.find(name) == alive_list.end()) {
            throw string("fail: cliente nao existe");
        }

        death_list[name] = alive_list[name];
        for(auto e : death_list[name].getOperations()) {
            death_oper[e.second->getId()] = e.second;
            alive_oper.erase(e.second->getId());
        }

        alive_list.erase(name);
    }
    string str() {
        stringstream ss;
        for(auto e : alive_list) {
            ss << ":) " << e.second.getName() << " " << total(e.second.getOperations())
            << "/" << e.second.getLimit() << endl;
        }

        for(auto e : alive_oper) {
            ss << "+ id:" << e.second->getId() << " ";
            if(e.second->getLabel() == 1) ss << "give";
            if(e.second->getLabel() == 2) ss << "take";
            if(e.second->getLabel() == 3) ss << "plus";
            ss << ":" << e.second->getName() << " " << e.second->getValue() << endl;
        }

        
        for(auto e : death_list) {
            ss << ":( " << e.second.getName() << " " << total(e.second.getOperations())
            << "/" << e.second.getLimit() << endl;
        }


        vector<pair<int, Operation*>> opera(death_oper.begin(), death_oper.end());

        sort(opera.begin(), opera.end(), [](const auto& a, const auto& b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }

            return a.second->getName() < b.second->getName();
        });

        for(auto e : opera) {
            ss << "- id:" << e.second->getId() << " ";
            if(e.second->getLabel() == 1) ss << "give";
            if(e.second->getLabel() == 2) ss << "take";
            if(e.second->getLabel() == 3) ss << "plus";
            ss << ":" << e.second->getName() << " " << e.second->getValue() << endl;
        }
        return ss.str();
    }
};

int main() {
    Shark shark;
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        }
        else if(cmd == "addCli") {
            string name;
            int limite {};
            ss >> name >> limite;
            try{
                shark.addCli(name, limite);
            } catch (string erro) {
                cout << erro << endl;
            }
        }
        else if(cmd == "show") {
            cout << shark.str();
        }
        else if(cmd == "showCli") {
            string name;
            ss >> name;
            try {
                cout << shark.getClient(name).str();
            } catch(string erro) {
                cout << erro << endl;
            }
        }
        else if(cmd == "kill") {
            string name;
            ss >> name;
            try {
                shark.kill(name);
            } catch (string erro) {
                cout << erro << endl;
            }
        }
        else if(cmd == "give") {
            string name;
            int value;
            ss >> name >> value;
            try {
                shark.give(name, value);
            } catch (string erro) {
                cout << erro << endl;
            }
        }
        else if(cmd == "take") {
            string name;
            int value;
            ss >> name >> value;
            try{
                shark.take(name, value);
            } catch (string erro) {
                cout << erro << endl;
            }
        }
        else if(cmd == "plus") {
            shark.plus();
        }
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
