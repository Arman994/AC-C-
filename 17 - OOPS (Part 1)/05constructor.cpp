#include <iostream>
using namespace std;

class Car {
    string name;
    string color;

public:
    Car() {
        cout << "constructor without parameters\n";
    }

    Car(string name, string color) {
        cout << "constructor with parameters\n";
        this->name = name;
        this->color = color;
    }

    void start() {
        cout << "car has started..\n";
    }

    void stop() {
        cout << "The car has stopped\n";
    }

    //Getter
    string getName() {
        return name;
    }
};


int main() {
    Car c0;
    Car c1("Lamborghini", "Black");
    cout << "car name : " << c1.getName() << endl;
    return 0;
}