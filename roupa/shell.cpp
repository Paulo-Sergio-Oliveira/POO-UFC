#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


class Roupa {
    string size;

    public: 

        Roupa(string size = ""): size(size) {}

        string str() {
            stringstream ss;
            ss << "size: (" << size << ")" << endl;
            return ss.str();
        }

        void setSize(string s) {
            if(s == "PP" || s == "P" || s == "M" || s == "G" || s == "GG" || s == "XG") {
                this->size = s;
                return;
            }

            cout << "fail: Valor inválido, tente PP, P, M, G, GG ou XG" << endl;
        }
};

int main() {
    Roupa roupa;
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "size") { // TENTE ATRIBUIR UM TAMANHO
            string size;
            ss >> size;
            roupa.setSize(size);
        } else if (cmd == "show") { // MOSTRE AS INFORMAÇÕES DO OBJETO
            cout << roupa.str();
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: Comando inválido" << endl;
        }
    }
}
