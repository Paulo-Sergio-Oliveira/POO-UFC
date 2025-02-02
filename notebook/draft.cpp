#include <iostream>
#include <sstream>
#include "fn.hpp"
using namespace std;

class Carregador {
    int potencia;

    public:

        Carregador(int potencia): potencia(potencia) {}

        int getPotencia() {
            return this->potencia;
        }

        string str() {
            return "Potência " + to_string(this->potencia) + "\n";
        }

        void mostrar() {
            cout << str();
        }
};

class Bateria {
    int capacidade;
    int carga;

    public:

        Bateria(int capacidade): capacidade(capacidade) {
            this->carga = capacidade;
        }

        int getCapacidade() {
            return this->capacidade;
        }

        int getCarga() {
            return this->carga;
        }

        void setCarga(int carga) {
            this->carga = carga;
        }

        string str() {
            stringstream ss;
            ss << "(" << this->carga << "/" << this->capacidade << ")";
            return ss.str();
        }

        void mostrar() {
            cout << str() << endl;
        }
};

class Notebook {
    bool ligado;
    shared_ptr<Bateria> bateria;
    shared_ptr<Carregador> carregador;

    public:

        Notebook(): ligado{false}, bateria{nullptr}, carregador{nullptr} {}

        bool isLigado() {
            return this->ligado;
        }

        void setBateria(shared_ptr<Bateria> b){
            this->bateria = b;
        }

        void setCarregador(shared_ptr<Carregador> c){
            this->carregador = c;
        }

        string str() {
            stringstream ss;
            ss << "Status: " << (ligado ? "Ligado" : "Desligado") << 
            ", Bateria: " << (bateria == nullptr ? "Nenhuma" : this->bateria->str()) << 
            ", Carregador: " << (carregador == nullptr ? "Desconectado\n" : this->carregador->str());
            return ss.str();
        }
        
        void ligar() {
            if(this->ligado) {
                cout << "já está ligado\n";
                return;
            }

            if((this->bateria == nullptr || this->bateria->getCarga() == 0) && this->carregador == nullptr) {
                cout << "não foi possível ligar\n";
                return;
            }

            this->ligado = true;
            cout << "notebook ligado\n";
        }

        void desligar() {
            if(!this->ligado) {
                cout << "já está desligado\n";
                return;
            }

            this->ligado = false;
            cout << "notebook desligado\n";
        }

        void usar(int min) {
            if(ligado) {
                if(this->carregador == nullptr && this->bateria->getCarga() - min <= 0) {
                    cout << "Usando por " + to_string(this->bateria->getCarga()) + " minutos, notebook descarregou\n";
                    this->desligar();
                    this->bateria->setCarga(0);
                    return;
                }

                if(this->carregador == nullptr) {
                    this->bateria->setCarga(this->bateria->getCapacidade() - min);
                    cout << "Usando por " + to_string(min) + " minutos\n";
                    return;
                }
                
                cout << "Notebook utilizado com sucesso\n";
                this->bateria->setCarga(min * this->carregador->getPotencia());
                return;
            }

            cout << "erro: ligue o notebook primeiro\n"; 
        }

        void mostrar() {
            cout << str();
        }
};

int main() {
    Notebook notebook = Notebook();
    notebook.mostrar();
    notebook.ligar();
    notebook.usar(10);

    auto bateria = make_shared<Bateria>(50);
    bateria->mostrar();
    notebook.setBateria(bateria);

    notebook.mostrar();
    notebook.ligar();
    notebook.mostrar();
    notebook.usar(30);
    notebook.mostrar();
    notebook.usar(30);
    notebook.mostrar();

    notebook.setBateria(nullptr);
    bateria->mostrar();
    notebook.mostrar();

    auto carregador = make_shared<Carregador>(2);
    carregador->mostrar();

    notebook.setCarregador(carregador);
    notebook.mostrar();
    notebook.ligar();
    notebook.mostrar();

    notebook.setBateria(bateria);
    notebook.mostrar();
    notebook.usar(10);
    notebook.mostrar();
}

