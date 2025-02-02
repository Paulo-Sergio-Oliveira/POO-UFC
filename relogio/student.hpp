#pragma once
#include "fn.hpp"
#include <iostream>
using namespace std;

class Clock {
private: 
    int hora {0};
    int min {0};
    int seg {0};

public:
    Clock (int hora = 0, int min = 0, int seg = 0) {
        setHour(hora);
        setMinute(min);
        setSecond(seg);
    }

    string str () {
        return (ostringstream() << setw(2) << setfill('0') << hora << ":"
        << setw(2) << setfill('0') << min << ":"
        << setw(2) << setfill('0') << seg).str();
    }

    int getHour () const {
        return this->hora;
    }

    int getMinute () const {
        return this->min;
    }

    int getSecond () const {
        return this->seg;
    }

    void setHour (int h) {
        if (h < 24 && h >= 0) {
            this->hora = h;
        } else {
            cout << "fail: hora invalida\n";
        }
    }

    void setMinute (int m) {
        if (m < 60 && m >= 0) {
            this->min = m;
        } else {
            cout << "fail: minuto invalido\n";
        }
    }

    void setSecond (int s) {
        if (s < 60 && s >= 0) {
            this->seg = s;
        } else {
            cout << "fail: segundo invalido\n";
        }
    }

    void nextSecond() {
        if (seg + 1 == 60) {
            setSecond(0);
            if (min + 1 == 60) {
                setMinute(0);
                if (hora + 1 == 24) {
                    setHour(0);
                } else {
                    setHour(hora + 1);
                }
            } else {
                setMinute(min + 1);
            }
        } else {
            setSecond(seg + 1);
        }
    }
};

class Student {
private:
    Clock clock;

public:
    Student(int hour = 0, int minute = 0, int second = 0) {
        this->clock = Clock(hour, minute, second);
    }

    void setHour(int hour) {
        this->clock.setHour(hour);
    }

    void setMinute(int minute) {
        this->clock.setMinute(minute);
    }
    void setSecond(int second) {
        this->clock.setSecond(second);
    }

    void nextSecond() {
        this->clock.nextSecond();
    }
    
    void show() {
        cout << this->clock.str() << endl;
    }
};