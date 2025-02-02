#include <iostream>
using namespace std;

class Chinela {
    int size;

    public:
        Chinela(): size{0} {}

        int getSize() {
            return this->size;
        }

        void setSize(int s) {
            if(s >= 20 && s <= 50 && s%2 == 0) {
                this->size = s;
                return;
            }

            cout << "Tamanho inválido!\n" <<
            "O valor inserido não está entre 20 e 50 ou não é par." << endl;
        }
};

int main() {
    Chinela chinela;

    while(chinela.getSize() == 0) {
        int size;

        cout << "Digite seu tamanho de chinela:" << endl;
        cin >> size;

        chinela.setSize(size);

        if(chinela.getSize() != 0) {
            cout << "Parabéns, você comprou uma chinela tamanho " << chinela.getSize() << endl;
        }
    }
}