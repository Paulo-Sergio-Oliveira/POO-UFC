#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

class Jogador {
    int numero;
    int casa;
    bool livre;

    public:

        Jogador(int numero): numero(numero), casa(0), livre(true) {}

        bool isFree() {
            return livre;
        }

        void setFree(bool l) {
            livre = l;
        }

        int getPos() {
            return casa;
        }

        void setPos(int c) {
            casa = c;
        }

        int getNumero() {
            return numero;
        }

        string str() {
            stringstream ss;
            ss << "player" << numero;
            return ss.str();
        }
};

class Tabuleiro {
    vector<int> armadilhas;
    vector<Jogador> jogadores;
    int tamanho;
    bool valendo;

    public: 

        Tabuleiro(int quantos = 0, int tamanho = 0): tamanho(tamanho), valendo(true){
            for(int i = 0; i < quantos; i++) {
                jogadores.push_back(Jogador(i+1));
            }
        }

        void addTrap(int trap) {
            armadilhas.push_back(trap);
        }

        void roll(int dado) {
            if(!valendo) {
                cout << "game is over" << endl;
                return;
            }

            if(!jogadores[0].isFree()) {
                if(dado%2 == 0) {
                    cout << jogadores[0].str() << " se libertou" << endl;
                    jogadores[0].setFree(true);
                } else {
                    cout << jogadores[0].str() << " continua preso" << endl;
                }

                jogadores.push_back(jogadores[0]);
                jogadores.erase(jogadores.begin());

                return;
            }

            if(jogadores[0].getPos() + dado > tamanho) {
                cout << jogadores[0].str() << " ganhou" << endl;
                jogadores[0].setPos(tamanho);
                valendo = false;
            } else {
                cout << jogadores[0].str() << " andou para " << jogadores[0].getPos() + dado << endl;
                jogadores[0].setPos(jogadores[0].getPos() + dado);
            }

            for(auto trap : armadilhas) {
                if(jogadores[0].getPos() == trap) {
                    cout << jogadores[0].str() << " caiu em uma armadilha" << endl;
                    jogadores[0].setFree(false);
                    break;
                }    
            }

            jogadores.push_back(jogadores[0]);
            jogadores.erase(jogadores.begin());
        }

        string str() {
            stringstream ss;

            for(auto jog : jogadores) {
                ss << jog.str() << ": ";

                for(int i = 0; i <= tamanho; i++) {
                    if(i == jog.getPos()) {
                        ss << jog.getNumero();
                    } else {
                        ss << ".";
                    }
                }

                ss << endl;
            }

            ss << "traps__: ";
            int pos = 0;
            for(int i = 0; i <= tamanho; i++) {
                if(armadilhas.size() > 0 && i == armadilhas[pos]) {
                    ss << "x";
                    pos++;
                } else {
                    ss << ".";
                }
            }

            return ss.str();
        }
};

int main() {
    Tabuleiro tabuleiro;
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int nPlayers, size;
            ss >> nPlayers >> size;
            tabuleiro = Tabuleiro(nPlayers, size);
        } else if (cmd == "addTrap") {
            int pos;
            ss >> pos;
            tabuleiro.addTrap(pos);
        } else if (cmd == "roll") {
            int value;
            ss >> value;
            tabuleiro.roll(value);
        } else if (cmd == "show") {
            cout << tabuleiro.str() << endl;
        } else {
            cout << "fail: command not found" << endl;
        }

    }
}
