#include <iostream>
#include <vector>
#include <list>
#include "fn.hpp"
using namespace std;

class Pessoa {
    string nome;

    public:
        
        Pessoa(string nome): nome(nome) {}

        string str() {
            return this->nome;
        }

        string getNome() {
            return this->nome;
        }

        void setNome(string nome) {
            this->nome = nome;
        }
};

class Mercantil {
    vector<shared_ptr<Pessoa>> caixas;
    list<Pessoa> espera;

    public:

        Mercantil(int qtdCaixas): caixas(qtdCaixas, nullptr) {}

        string str() {
            string caixasStr = "[";
            for (size_t i = 0; i < caixas.size(); i++) {
                caixasStr += (caixas[i] != nullptr ? caixas[i]->getNome() : "-----");

                if (i < caixas.size() - 1) 
                    caixasStr += ", ";
            }
            caixasStr += "]";

            string esperaStr = "[";
            for(auto i = espera.begin(); i != espera.end(); i++) {
                esperaStr += i->getNome();
                
                if(next(i) != espera.end())
                    esperaStr += ", ";
            }
            esperaStr += "]";

            return "Caixas: " + caixasStr + "\nEspera: " + esperaStr;
        }

        void chegar(const Pessoa& pessoa) {
            espera.push_back(pessoa);
        }

        void chamar(int posicao) {
            if(posicao < 0 || posicao >= static_cast<int>(caixas.size())) {
                cout << "fail: caixa inexistente" << endl;
                return;
            }
            
            if(espera.empty()) {
                cout << "fail: sem clientes" << endl;
                return;
            }

            if(caixas[posicao] != nullptr) {
                cout << "fail: caixa ocupado" << endl;
                return;
            }

            caixas[posicao] = make_shared<Pessoa>(espera.front());
            espera.pop_front();
        }

        void finalizar(int posicao) {
            if(posicao < 0 || posicao >= static_cast<int>(caixas.size())) {
                cout << "fail: caixa inexistente" << endl;
                return;
            }

            if(caixas[posicao] == nullptr) {
                cout << "fail: caixa vazio" << endl;
                return;
            }

            caixas[posicao] = nullptr;
        }
};

class Adapter {
    Mercantil bank;
public:
    Adapter(int qtd_caixas): bank(qtd_caixas) {}

    void call(int indice) {
        bank.chamar(indice);
    }
    void finish(int indice) {
        bank.finalizar(indice);
    }
    void arrive(const std::string& nome) {
        bank.chegar(Pessoa(nome));
    }

    void show() {
        fn::write(bank.str());
    }
};