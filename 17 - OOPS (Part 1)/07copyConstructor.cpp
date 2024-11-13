#include <iostream>
using namespace std;

class Car {
    public:
        string name;
        string color;
    
    Car(string name, string color) {
        this->name = name;
        this->color = color;
    }

    Car(Car &original) {//Custom copy constructor
        cout << "copying original to new..\n";
        name = original.name;
        color = original.color;
    }
};

int main() {
    Car c1("SuperPro", "Black");
    Car c2(c1);//Copying constructor

    cout << "name : " << c2.name << endl;//Superpro
    cout << "color : " << c2.color << endl;//Black
    return 0;
}