#include <iostream>
#include <sstream>
using namespace std;

class Towel {
    string color;
    string size;
    int wetness;

    public:

        Towel(string color = "", string size = ""): color(color), size(size), wetness(0) {}

        void dry(int amount) {
            wetness += amount;

            if(wetness >= getMaxWetness()) {
                wetness = getMaxWetness();
                cout << "toalha encharcada" << endl;
            }
        }

        void wringOut() {
            wetness = 0;
        }

        int getMaxWetness() {
            if (size == "P"){
                return 10;
            }

            if (size == "M"){
                return 20;
            }

            if (size == "G"){
                return 30;
            }

            return 0;
        }
        
        bool isDry() {
            if(wetness == 0) {
                return true;
            }

            return false;
        }

        string str() {
            stringstream ss;
            ss << "Cor: " << color << ", Tamanho: " << size << ", Umidade: " << wetness << endl;
            return ss.str();
        }

        void show() {
            cout << str();
        }
};

int main() {
    Towel towel;
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream par(line);
        par >> cmd;

        if (cmd == "mostrar") { // MOSTRE A TOALHA
            towel.show();
        } 
        else if (cmd == "criar") { // ATUALIZE A TOALHA UTILIZAND O CONSTRUTOR
            string cor, tamanho;
            par >> cor >> tamanho;
            towel = Towel(cor, tamanho);
        } 
        else if (cmd == "enxugar") { // USE O METODO ENXUGAR
            int umidade {};
            par >> umidade;
            towel.dry(umidade);
        } 
        else if (cmd == "torcer") { // USE O METODO TORCER
            towel.wringOut();
        } 
        else if (cmd == "seca") { // VERIFIQUE SE ESTA SECA E IMPRIMA "sim" OU "nao"
            cout << (towel.isDry() ? "sim" : "nao") << endl;
        } 
        else if (cmd == "end") {
            break;
        } 
        else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
