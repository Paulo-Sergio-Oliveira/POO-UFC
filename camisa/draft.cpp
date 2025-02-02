#include <iostream>
using namespace std;

class Roupa {
    string size;

    public:
        Roupa(): size{""} {}

        string getSize() {
            return this->size;
        }

        void setSize(string s) {
            if(s == "PP" || s == "P" || s == "M" || s == "G" || s == "GG" || s == "XG") {
                this->size = s;
                return;
            }

            cout << "Tamanho inválido!\n" <<
            "O valor inserido não está entre 'PP', 'P', 'M' e 'G', 'GG' e 'XG'." << endl;
        }
};

int main() {
    Roupa roupa;

    while(roupa.getSize() == "") {
        string size;

        cout << "Digite seu tamanho de roupa:" << endl;
        cin >> size;

        roupa.setSize(size);
        
        if(roupa.getSize() != "") {
            cout << "Parabéns, você comprou uma roupa tamanho " << roupa.getSize() << endl;
        }
    }
}