#include <iostream>
using namespace std;

class Car {
    public:
        string name;
        string color;
        int *milage;
    
    Car(string name, string color) {
        this->name = name;
        this->color = color;
        milage = new int; //Dynamic allocation
        *milage = 12;
    }

    Car(Car &original) {//Custom copy constructor
        cout << "copying original to new..\n";
        name = original.name;
        color = original.color;
        milage = new int;
        *milage = *original.milage;
    }
};

int main() {
    Car c1("SuperPro", "Black");

    Car c2(c1);

    // cout << c2.name << endl;
    // cout << c2.color << endl;
    // cout << *c2.milage << endl;//don't forget to dereference it
    // *c2.milage = 10;

    // cout << *c1.milage << endl;//works fine without the Custom copy constructor and it is shalloq copy
    
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.milage << endl;//don't forget to dereference it
    *c2.milage = 10;

    cout << *c1.milage << endl;//Custom copy constructor is required for deep copy
    return 0;
}