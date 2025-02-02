#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool buscaX(vector<int> filled) {
        cout << "Busca elemento X: ";

        int x{5};

        for (int& elem : filled) {
            if(elem == x) {
                return true;
            }
        }

        return false;
}

int main() {
    vector<int> empty {};

    cout << "Array vazio: ";
    for (int& elem : empty) {
        cout << " " << elem;
    }
    cout << endl;

    vector<int> filled {1, 2, 3, 4, 5};
    
    cout << "Array preenchido:";
    for (int& elem : filled) {
        cout << " " << elem;
    }
    cout << endl;

    filled.push_back(6);

    cout << "Adicionando no final:";
    for (int& elem : filled) {
        cout << " " << elem;
    }
    cout << endl;

    filled.pop_back();

    cout << "Removendo do final:";
    for (int& elem : filled) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Array formatado:";
    for (vector<int>::const_iterator i = filled.cbegin(); i != filled.cend(); i++) {
        cout << " " << *i;
    }
    cout << endl;

    vector<int> sequence {};
    for (int i = 0; i < 10; i++) {
        sequence.push_back(i);
    }
    
    cout << "Sequência de 0 a n:";
    for (int& elem : sequence) {
        cout << " " << elem;
    }
    cout << endl;

    vector<int> random {};
    for (int i = 0; i < 10; i++) {
        random.push_back(std::rand() % 100);
    }

    cout << "Valores aleatórios:";
    for (int& elem : random) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Acessando por índice: " << filled[5] << endl;

    cout << "For-Range: ";
    for (int& elem : filled) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "For Indexado: ";
    for (size_t i = 0; i < filled.size(); i++) {
        cout << " " << filled[i];
    }
    cout << endl;

    if(buscaX(filled)) {
        cout << "Elemento presente!" << endl;
    } else {
        cout << "Elemento ausente..." << endl;
    }
    
    cout << "Filtrando Pares:";

    vector<int> even{};
    for (int& elem : sequence) {
        if(elem % 2 == 0) {
            even.push_back(elem);
        }
    }

    for (int& elem : even) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Transformando em quadrados:";
    
    vector<int> square{};
    for (int& elem : sequence) {
        square.push_back(elem*elem);
    }

    for (int& elem : square) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Removendo X:";

    int x = 3;
    for (vector<int>::const_iterator i = filled.cbegin(); i != filled.cend(); i++) {
        if (*i == x) {
            filled.erase(i);
            break;
        }
    }

    for (int& elem : filled) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Removendo todo X:";

    x = 9;
    vector<int> remove {1, 9, 9, 2, 9, 3, 4, 9, 9, 9, 5};
    vector<int> removed {};

    for (int& elem : remove) {
        if (elem != x) {
            removed.push_back(elem);
        }
    }

    remove = removed;

    for (int& elem : remove) {
        cout << " " << elem;
    }
    cout << endl;

    vector<int> v = {1, 3, 6, 2, 9};
    x = 6;

    cout << "Busca: ";

    auto it = find(v.begin(), v.end(), x);

    cout << "Elemento " << x << " está na posição " << distance(v.begin(), it) << endl;

    cout << "Remoção:";

    v.erase(it);  

    for (int& elem : v) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Ordenação:";

    sort(random.begin(), random.end());

    for (int& elem : random) {
        cout << " " << elem;
    }
    cout << endl;

    cout << "Embaralhamento:";

    random_shuffle(sequence.begin(), sequence.end());

    for (int& elem : sequence) {
        cout << " " << elem;
    }
    cout << endl;
}

