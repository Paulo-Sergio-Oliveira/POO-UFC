#include <iostream>
#include <memory>
#include <sstream>
#include <list>
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

class Kid {
    string name;
    int age;

public:

    Kid(string name, int age): name(name), age(age) {}

    string getName(){
        return name;
    }

    void setName(string n){
        name = n;
    }

    int getAge(){
        return age;
    }

    void setAge(int a){
        age = a;
    }

    string str() {
        stringstream ss;
        ss << name << ":" << age;
        return ss.str();
    }
};

class Trampoline {
    list<shared_ptr<Kid>> playing;
    list<shared_ptr<Kid>> waiting;

public:

    Trampoline() {}

    void arrive(shared_ptr<Kid> kid) {
        waiting.push_front(kid);
    }

    void enter() {
        if(waiting.empty()) {
            return;
        }

        playing.push_front(waiting.back());
        waiting.pop_back();
    }

    void leave() {
        if(playing.empty()) {
            return;
        }

        waiting.push_front(playing.back());
        playing.pop_back();
    }

    void removeKid(string name) {
        for(auto it = waiting.begin(); it != waiting.end(); it++) {
            if(it->get()->getName() == name){
                waiting.erase(it);
                return;
            }
        }

        for(auto it = playing.begin(); it != playing.end(); it++) {
            if(it->get()->getName() == name){
                playing.erase(it);
                return;
            }
        }
        
        cout << "fail: " << name << " nao esta no pula-pula" << endl;
    }

    string str() {
        stringstream ss;
        auto geral = [](auto x) { return x->str(); };
        ss << "[" << (waiting.empty() ? "" : map_join(waiting, geral, ", ")) << "]"
           << " => [" << (playing.empty() ? "" : map_join(playing, geral, ", ")) << "]";
        return ss.str();
    }
};

int main() {
    Trampoline jump;
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            cout << jump.str() << endl;
        } else if (cmd == "arrive") {
            string name;
            int age;
            ss >> name >> age;
            jump.arrive(make_shared<Kid>(name, age));
        } else if (cmd == "enter") {
            jump.enter();
        } else if (cmd == "leave") {
            jump.leave();
        } else if (cmd == "remove") {
            string name;
            ss >> name;
            jump.removeKid(name);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
