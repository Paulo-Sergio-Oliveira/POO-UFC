#pragma once
#include <iostream>
#include "fn.hpp"
using namespace std;

class Person {
    private:

        int age{0};
        string name{""};

    public:

        Person (string name, int age): age(age), name(name) {}

        int getAge() {
            return this->age;
        }

        string getName() {
            return this->name;
        }

        string str() const {
            return name + ":" + to_string(age);
        }
};

ostream& operator<<(ostream &os, const Person& person){
        return os << person.str();
}

class Motorcycle {
    private:

        shared_ptr<Person> person{nullptr};
        int power{1};
        int time{0};

    public:

        Motorcycle(int power): power(power) {}

        bool insertPerson(shared_ptr<Person> p) {
            if(person == nullptr){
                this->person = p;
                return true;
            } else {
                cout << "fail: busy motorcycle" << endl;
                return false;
            }
        }

        shared_ptr<Person> remove() {
            shared_ptr<Person> persona = person;

            if(person != nullptr){
                person = nullptr;
                return persona;
            } else {
                cout << "fail: empty motorcycle" << endl;
                return person;
            }
        }

        void buyTime(int t) {
            time += t;
        }

        void drive(int drive) {
            if(time == 0) {
                cout << "fail: buy time first" << endl;
                return;
            }

            if(person == nullptr) {
                cout << "fail: empty motorcycle" << endl;
                return;
            }

            if(person->getAge() > 10){
                cout << "fail: too old to drive" << endl;
                return;
            }

            if(time - drive < 0){
                cout << "fail: time finished after " + to_string(time) + " minutes" << endl;
                time = 0;
                return;
            }
            
            time -= drive;
        }

        string honk() const {
            return "P" + string(power, 'e') + "m";
        }

        string str() const {
            string persona("empty");

            if (person != nullptr){
                persona = person->str();
            }

            return fn::format("power:{}, time:{}, person:({})", this->power, this->time, persona) ;
        }
};

ostream& operator<<(ostream &os, const Motorcycle& motorcycle){
        return os << motorcycle.str();
}

class Student {
    Motorcycle motorcycle;
public:

    Student(int power = 1): motorcycle(power) {}

    void init(int power = 1) {
        motorcycle = Motorcycle(power);
    }

    void enter(std::string name, int age) {
        auto person = std::make_shared<Person>(name, age);
        motorcycle.insertPerson(person);
    }

    void leave() {
        auto person = motorcycle.remove();
        fn::write(person == nullptr ? "---" : person->str());
    }

    void honk() const {
        fn::write(motorcycle.honk());
    }

    void buy(int time) {
        motorcycle.buyTime(time);
    }

    void drive(int time) {
        motorcycle.drive(time);
    }

    void show() const {
        fn::write(motorcycle);
    }
};