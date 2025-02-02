#pragma once
#include "fn.hpp"

struct Animal {
    int idade;
    std::string especie;
    std::string barulho;

    Animal(std::string especie = "", std::string barulho = "") {
        this->especie = especie;
        this->barulho = barulho;
        this->idade = 0;
    }

    std::string str() const {
        return especie + ":" + std::to_string(idade) + ":" + barulho;
    }
    
    std::string fazerBarulho() const{
        if (idade == 0) {
            return "---";
        }
        
        if (idade == 4) {
            return "RIP";
        }
        
        return barulho;
    }
    
    void crescer(int etapas) {
        idade += etapas;
        if (idade >= 4) {
            std:: cout << "warning: " + especie + " morreu\n";
            idade = 4;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const Animal& animal){
    return os << animal.str();
}

struct Student {
    Animal animal;
    
    Student(std::string especie = "", std::string barulho = "") {
        animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        animal.crescer(nivel);
    }

    void noise() {
        std::cout << animal.fazerBarulho() << std::endl;
    }

    void show() {
        std::cout << animal << std::endl;
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