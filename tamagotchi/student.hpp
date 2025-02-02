#include <iostream>
#include <string>
#include "fn.hpp"
using namespace std;

class Pet {
    private:

        int energyMax;
        int hungryMax;
        int cleanMax;
        int energy;
        int hungry;
        int clean;
        int diamonds{0};
        int age{0};
        bool alive;

    public:

        Pet(int energy, int hungry, int clean): energy(energy), hungry(hungry), clean(clean) {
            this->energyMax = energy;
            this->hungryMax = hungry;
            this->cleanMax = clean;
        }

        int getEnergyMax() {
            return this->energyMax;
        }

        int getHungryMax() {
            return this->hungryMax;
        }

        int getCleanMax() {
            return this->cleanMax;
        }

        int getEnergy() {
            return this->energy;
        }
    
        void setEnergy(int energy) {
            this->energy = energy;

            if(this->energy > this->energyMax) {
                this->energy = this->energyMax;
            }

            if(this->energy <= 0) {
                this->alive = false;
                this->energy = 0;
            }
        }
    
        int getHungry() {
            return this->hungry;
        }
    
        void setHungry(int hungry) {
            this->hungry = hungry;

            if(this->hungry > this->hungryMax) {
                this->hungry = this->hungryMax;
            }

            if(hungry <= 0) {
                this->alive = false;
                this->hungry = 0;
            }
        }
    
        int getClean() {
            return this->clean;
        }
    
        void setClean(int clean) {
            this->clean = clean;

            if(this->clean > this->cleanMax) {
                this->clean = this->cleanMax;
            }

            if(clean <= 0) {
                this->alive = false;
                this->clean = 0;
            }
        }
    
        int getDiamonds() {
            return this->diamonds;
        }
    
        void setDiamonds(int diamonds) {
            this->diamonds = diamonds;
        }
    
        int getAge() {
            return this->age;
        }
    
        void setAge(int age) {
            this->age = age;
        }
    
        bool isAlive() {
            return this->alive;
        }

        string str() {
            return fn::format("E:{}/{}, S:{}/{}, L:{}/{}, D:{}, I:{}", energy, energyMax,
            hungry, hungryMax, clean, cleanMax, diamonds, age);
        }
};

class Game {
    private:

        Pet pet;

        bool testAlive() {
            return pet.isAlive();
        }
    
    public:

        Game(Pet pet): pet(pet) {}

        void play() {
            if(testAlive()) {
                pet.setEnergy(pet.getEnergy() - 2);
                pet.setHungry(pet.getHungry() - 1);
                pet.setClean(pet.getClean() - 3);
                pet.setDiamonds(pet.getDiamonds() + 1);
                pet.setAge(pet.getAge() + 1);

                if (pet.getEnergy() <= 0) {
                    cout << "fail: pet morreu de fraqueza" << endl;
                    return;
                }

                if (pet.getHungry() <= 0) {
                    cout << "fail: pet morreu de fome" << endl;
                    return;
                }

                if (pet.getClean() <= 0) {
                    cout << "fail: pet morreu de sujeira" << endl;
                    return;
                }
            } else {
                cout << "fail: pet esta morto" << endl;
            }
        }

        void shower() {
            if(testAlive()) {
                pet.setEnergy(pet.getEnergy() - 3);
                pet.setHungry(pet.getHungry() - 1);
                pet.setClean(pet.getCleanMax());
                pet.setAge(pet.getAge() + 2);
            } else {
                cout << "fail: pet esta morto" << endl;
            }
        }

        void eat() {
            if(testAlive()) {
                pet.setEnergy(pet.getEnergy() - 1);
                pet.setHungry(pet.getHungry() + 4);
                pet.setClean(pet.getClean() - 2);
                pet.setAge(pet.getAge() + 1);
            } else {
                cout << "fail: pet esta morto" << endl;
            }
        }

        void sleep() {
            if(testAlive()) {
                if(pet.getEnergyMax() - pet.getEnergy() >= 5) {
                    pet.setAge(pet.getAge() + (pet.getEnergyMax() - pet.getEnergy()));
                    pet.setEnergy(pet.getEnergyMax());
                    pet.setHungry(pet.getHungry() - 1);
                } else {
                    cout << "fail: nao esta com sono" << endl;
                }
            } else {
                cout << "fail: pet esta morto" << endl;
            }
        }

        string str() {
            return pet.str();
        }
};

class Student {
private:
    Game game;
public:
    Student(int energy, int hungry, int clean): game(Pet(energy, hungry, clean)) {}

    void show() {
        std::cout << this->game.str() << std::endl;
    }

    void play() {
        this->game.play();
    }

    void shower() {
        this->game.shower();
    }

    void eat() {
        this->game.eat();
    }

    void sleep() {
        this->game.sleep();
    }
};
