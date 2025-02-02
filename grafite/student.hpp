#pragma once
#include <iostream>
#include <string>
#include "fn.hpp"
using namespace std;

class Lead {
    double thick;
    string hard;
    int size;

    public:
        Lead(double thick, string hard, int size): thick(thick), hard(hard), size(size) {}

        double getThickness() {
            return this->thick;
        }

        string getHardness() {
            return this->hard;
        }

        int getSize() {
            return this->size;
        }

        void setSize(int s) {
            this->size = s;
        }

        int usagePerSheet() {
            if(hard == "HB") {
                return 1;
            }

            if(hard == "2B") {
                return 2;
            }

            if(hard == "4B") {
                return 4;
            }

            if(hard == "6B") {
                return 6;
            }

            return 0;
        }

        string str() {
            return (std::ostringstream() << std::fixed << std::setprecision(1) 
            << thick << ":" << hard << ":" << size).str();
        }
};

class Pencil {
        double thick;
        shared_ptr<Lead> tip{nullptr};

    public:
        Pencil(double thick): thick(thick) {}

        bool hasGrafite() {
            if(tip != nullptr) {
                return true;
            }
            return false;
        }
        
        bool insert(shared_ptr<Lead> t) {
            if(t->getThickness() != thick) {
                cout << "fail: calibre incompativel" << endl;
                return false;
            }

            if(tip != nullptr){
                cout << "fail: ja existe grafite" << endl;
                return false;
                
            }

            tip = t;
            return true;
        }

        shared_ptr<Lead> remove() {
            auto graf = tip;
            if(tip != nullptr) {
                tip = nullptr;
                return graf;
            } else {
                return tip;
            }
        }

        void writePage() {
            if(tip == nullptr) {
                cout << "fail: nao existe grafite" << endl;
                return;
            }

            if(tip->getSize() == 10) {
                cout << "fail: tamanho insuficiente" << endl;
                return;
            }

            tip->setSize(tip->getSize() - tip->usagePerSheet());

            if(tip->getSize() < 10){
                cout << "fail: folha incompleta" << endl;
                tip->setSize(10);
                return;
            }
        }

        string str() {
            string graf("null");

            if(tip != nullptr) {
                graf = "[" + tip->str() + "]";
            }

            return (std::ostringstream() << "calibre: " << std::fixed << std::setprecision(1) 
            << thick << ", grafite: " << graf).str();
        }
};

class Student {
private:
    Pencil pencil;
public:
    Student(double thickness): pencil(thickness) {};
    
    void insert(double thickness, std::string hardness, int length) {
        pencil.insert(make_shared<Lead>(thickness, hardness, length));
    }

    void remove() {
        pencil.remove();
    }

    void writePage() {
        pencil.writePage();
    }

    void show() {
        fn::write(pencil.str());
    }
};
