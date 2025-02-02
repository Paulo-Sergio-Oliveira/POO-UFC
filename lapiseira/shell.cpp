#include <iostream>
#include <list>
#include <sstream>
#include <memory>
using namespace std;

// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "");
        ss << f(*it);
    }
    return ss.str();
}

class Ponta {
    float calibre;
    string dureza;
    int tamanho;

    public:

        Ponta(float calibre, string dureza, int tamanho): calibre(calibre), dureza(dureza), tamanho(tamanho) {}

        int usoPorFolha() {
            if(dureza == "HB"){
                return 1;
            }

            if(dureza == "2B"){
                return 2;
            }

            if(dureza == "4B"){
                return 4;
            }

            if(dureza == "6B"){
                return 6;
            }

            return 0;
        }

        int getTamanho() {
            return tamanho;
        }

        string getDureza() {
            return dureza;
        }

        float getCalibre() {
            return calibre;
        }

        void setTamanho(int t) {
            tamanho = t;
        }

        string str() {
            stringstream ss;
            ss << "[" << calibre << ":" << dureza << ":" << tamanho << "]";
            return ss.str();
        }
};

class Lapiseira {
    float calibre;
    shared_ptr<Ponta> ponta;
    list<shared_ptr<Ponta>> tambor;

    public:

        Lapiseira(float calibre = 0): calibre(calibre), ponta(nullptr) {}

        void insert(shared_ptr<Ponta> p) {
            if(p->getCalibre() != calibre) {
                cout << "fail: calibre incompatível" << endl;
                return;
            }

            tambor.push_back(p);
        }

        void pull() {
            if(ponta != nullptr){
                cout << "fail: ja existe grafite no bico" << endl;
                return;
            }

            ponta = tambor.front();
            tambor.pop_front();
        }

        void remove() {
            ponta = nullptr;
        }

        void write() {
            if(ponta == nullptr) {
                cout << "fail: nao existe grafite no bico" << endl;
                return;
            }

            if(ponta->getTamanho() == 10) {
                cout << "fail: tamanho insuficiente" << endl;
                return;
            }

            ponta->setTamanho(ponta->getTamanho() - ponta->usoPorFolha());

            if(ponta->getTamanho() < 10){
                cout << "fail: folha incompleta" << endl;
                ponta->setTamanho(10);
                return;
            }
        }

        string str() {
            stringstream ss;
            auto lstr = [](auto x) { return x->str(); } ;
            ss << "calibre: " << calibre << ", bico: "
               << (ponta != nullptr ? ponta->str() : "[]")
               << ", tambor: <" << map_join(tambor, lstr, "") << ">";
            return ss.str();
        }
};

int main() {
    Lapiseira lapiseira;
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
            cout << lapiseira.str() << endl;
        } 
        else if (cmd == "init") { 
            float calibre;
            ss >> calibre;
            lapiseira = Lapiseira(calibre);
        } 
        else if (cmd == "insert") { 
            float calibre;
            string dureza;
            int tamanho;
            ss >> calibre >> dureza >> tamanho;
            lapiseira.insert(make_shared<Ponta>(calibre, dureza, tamanho));
        } 
        else if (cmd == "remove") { 
            lapiseira.remove();
        } 
        else if (cmd == "pull") {
            lapiseira.pull();
        } 
        else if (cmd == "write") {
            lapiseira.write(); 
        } 
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
