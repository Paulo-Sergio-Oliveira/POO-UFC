#pragma once
#include "fn.hpp"

struct Calculator {
    int battery;
    int batteryMax;
    float display;

    Calculator (int batteryMax = 0, int battery = 0, float display = 0) {
        this->battery = battery;
        this->batteryMax = batteryMax;
        this->display = display;
    }

    std::string str () {
        return (std::ostringstream() << "display = " << std::fixed << std::setprecision(2) 
            << display << ", battery = " << battery).str();
    }

    void charge (int value) {
        battery += value;

        if(battery > batteryMax){
            battery = batteryMax;
        }
    }

    void sum (int a, int b) {
        if (battery == 0) {
            std::cout << "fail: bateria insuficiente\n";
            return;
        }

        display = a + b;
        battery--;
    }

    void div (int a, int b) {
        if (battery == 0) {
            std::cout << "fail: bateria insuficiente\n";
            return;
        }

        if (b == 0) {
            std::cout << "fail: divisao por zero\n";
            battery--;
            return;
        }

        display = (float) a / b;
        battery--;
    }
};

class Student {
    Calculator c;
public:
    Student() {
        c = Calculator(0);
    }
    void show() {
        std::cout << c.str() << std::endl;
    }
    void init(int batteryMax) {
        c = Calculator(batteryMax);
    }
    void charge(int value) {
        c.charge(value);
    }
    void sum(int a, int b) {
        c.sum(a, b);
    }
    void div(int num, int den) {
        c.div(num, den);
    }
};
