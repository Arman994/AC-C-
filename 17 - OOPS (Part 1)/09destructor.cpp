#include <iostream>
using namespace std;

class Car {
    public:
        string name;
        string color;
        int *mileage;
    
    Car(string name, string color) {
        this->name = name;
        this->color = color;
        mileage = new int; 
        *mileage = 12;
    }

    Car(Car &original) {
        cout << "copying original to new..\n";
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }

    ~Car() {                           //Careful about the ~(Not) sign
        cout << "deleting object..\n";
        if(mileage != NULL) {
            delete mileage;
            mileage = NULL;
        }
    }
};

int main() {
    Car c1("SuperPro", "Black");
    cout << c1.name << endl;
    cout << c1.color << endl;
    cout << *c1.mileage << endl;

    return 0;
}