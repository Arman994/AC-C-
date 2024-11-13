//Predict the output

#include <iostream>
using namespace std;

class Base {
public:
    virtual void print() {
        cout << "base\n";
    }
};

class Derived : public Base {
    void print() {
        cout << "Derived\n";
    }
};

int main() {
    Base* b = new Derived;   //Runtime polymorphism so override
    b->print();
    delete b;
    return 0;
}