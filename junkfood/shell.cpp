#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template<typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& cont, FUNC func, string delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim);
        ss << func(*it);
    }
    return ss.str();
}

class Espiral {
    string nome;
    int qtd;
    double preco;

public:
    Espiral(string n, int q, double p): nome(n), qtd(q), preco(p) {};

    string getNome() {
        return this->nome;
    }

    void setNome(string n) {
        this->nome = n;
    }

    double getPreco() {
        return this->preco;
    }

    void setPreco(double p) {
        this->preco = p;
    }

    int getQtd() {
        return this->qtd;
    }

    void setQtd(int q) {
        this->qtd = q;
    }

    string str() {
        stringstream ss;
        ss << "[" << setw(8) << setfill(' ')
           << nome << " : " << qtd << " U : "
           << fixed << setprecision(2) << preco
           << " RS]";
        return ss.str();

    }
};

class Maquina {
    vector<Espiral> espirais;
    double saldo;
    double lucro;

public:

    Maquina(int qtd = 0) {
        espirais = vector<Espiral>(qtd, Espiral("empty", 0, 0));
        saldo = 0;
        lucro = 0;
    }

    void setEspiral(int i, string n, int q, double p) {
        if(i < 0 || i > (int) espirais.size()) {
            cout << "fail: indice nao existe" << endl;
            return;
        }

        espirais[i] = Espiral(n, q, p);
    }

    void limpar(int i) {
        espirais[i] = Espiral("empty", 0, 0);
    }

    void addGrana(double grana) {
        saldo += grana;
    }

    void pegaTroco() {
        cout << "voce recebeu " << fixed << setprecision(2)
             << saldo << " RS" << endl;
        saldo = 0;
    }

    void comprar(int i) {
        if(i < 0 || i > (int) espirais.size()) {
            cout << "fail: indice nao existe" << endl;
            return;
        }

        if(saldo < espirais[i].getPreco()) {
            cout << "fail: saldo insuficiente" << endl;
            return;
        }

        if(espirais[i].getQtd() <= 0) {
            cout << "fail: espiral sem produtos" << endl;
            return;
        }

        espirais[i].setQtd(espirais[i].getQtd() - 1);
        saldo -= espirais[i].getPreco();

        cout << "voce comprou um " << espirais[i].getNome() << endl;
    }

    string str() {
        stringstream ss;
        ss << "saldo: " << fixed << setprecision(2) << saldo << endl;
        for(size_t i = 0; i < espirais.size(); i++) {
            ss << i << " " << espirais[i].str() << endl;
        }
        return ss.str();
    }
};


int main() {
    Maquina maquina;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        try {
            if (cmd == "show") {
                cout << maquina.str();
            } else if (cmd == "init") {
                int n_espirais {};
                ss >> n_espirais;
                maquina = Maquina(n_espirais);
            } else if (cmd == "limpar") {
                int indice {};
                ss >> indice;
                maquina.limpar(indice);
            } else if (cmd == "dinheiro") {
                int value {};
                ss >> value;
                maquina.addGrana(value);
            } else if (cmd == "comprar") {
                int index {};
                ss >> index;
                maquina.comprar(index);
            } else if (cmd == "set") {
                int index {};
                string name;
                int qtd {};
                double price {};
                ss >> index >> name >> qtd >> price;
                maquina.setEspiral(index, name, qtd, price);
            } else if (cmd == "troco") {
                maquina.pegaTroco();
            } else if (cmd == "end") {
                break;
            } else {
                cout << "comando invalido" << endl;
            }
        } catch (const char* e) {
            cout << e << endl;
        }
    }
}
