#include "fn.hpp"

struct Car {
    int gas;
    int gasMax;
    int pass;
    int passMax;
    int km;

    Car (int gas = 0, int pass = 0, int km = 0, int passMax = 2, int gasMax = 100){
        this->gas = gas;
        this->pass = pass;
        this->km = km;
        this->gasMax = gasMax;
        this->passMax = passMax;
    }

    std::string str() {
        return "pass: " + std::to_string(pass) + 
        ", gas: " + std::to_string(gas) + 
        ", km: " + std::to_string(km);
    }

    void enter() {
        pass++;

        if (pass > 2) {
            std::cout << "fail: limite de pessoas atingido\n";
            pass = 2;
        }
    }

    void leave() {
        pass--;

        if (pass < 0) {
            std::cout << "fail: nao ha ninguem no carro\n";
            pass = 0;
        }
    }

    void fuel (int qtd) {
        gas += qtd;

        if (gas > 100) {
            gas = 100;
        }
    }

    void drive (int dist) {
        if (pass == 0) {
            std::cout << "fail: nao ha ninguem no carro\n";
            return;
        }

        if (gas == 0) {
            std::cout << "fail: tanque vazio\n";
            return;
        }

        if (dist > gas) {
            std::cout << "fail: tanque vazio apos andar " + std::to_string(gas) + " km\n";
            km += gas;
            gas = 0;
            return;
        }

        km += dist;
        gas -= dist;
    }
};

struct Student {
    Car car;
    Student(int gas = 0, int pass = 0, int km = 0, int passMax = 2, int gasMax = 100) {
        car = Car(gas, pass, km, passMax, gasMax);
    }

    void enter() {
        car.enter();
    }

    void leave() {
        car.leave();
    }

    void fuel(int q) {
        car.fuel(q);
    }

    void drive(int q) {
        car.drive(q);
    }

    void show() {
        std::cout << car.str() << std::endl;
    }
};

struct Debug {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};
