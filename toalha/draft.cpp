#include <iostream>
#include <sstream>
using namespace std;

class Towel {
    string color;
    string size;
    int wetness;

    public:

        Towel(string color, string size): color(color), size(size), wetness(0) {}

        void dry(int amount) {
            wetness += amount;

            if(wetness > getMaxWetness()) {
                wetness = getMaxWetness();
                cout << "Toalha encharcada" << endl;
            }
        }

        void wringOut() {
            wetness = 0;
        }

        int getMaxWetness() {
            if (size == "P"){
                return 10;
            }

            if (size == "M"){
                return 20;
            }

            if (size == "G"){
                return 30;
            }

            return 0;
        }
        
        bool isDry() {
            if(wetness == 0) {
                return true;
            }

            return false;
        }

        string str() {
            stringstream ss;
            ss << color << " " << size << " " << wetness << endl;
            return ss.str();
        }

        void show() {
            cout << str();
        }
};

int main() {
    Towel towel = Towel("Azul", "P");
    towel.show();
    towel.dry(5);
    towel.show();
    cout << (towel.isDry() ? "True" : "False") << endl;
    towel.dry(5);
    towel.show();
    towel.dry(5);
    towel.show();

    towel.wringOut();
    towel.show();

    Towel towel2 = Towel("Verde", "G");
    cout << (towel2.isDry() ? "True" : "False") << endl;
    towel2.dry(30);
    towel2.show();
    cout << (towel2.isDry() ? "True" : "False") << endl;
    towel2.dry(1);
}

