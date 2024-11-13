#include <iostream>
using namespace std;

class Parent {
public:
    void show() {
        cout << "parent class show\n";
    }

    virtual void hello() {
        cout << "parent hello\n";
    }    
};

class Child : public Parent {
public:
    void show() {
        cout << "child class show\n";
    }
    void hello() {           //   Compulsory to redefine in in child class. virtual word not needed
        cout << "child hello\n";
    } 
};

int main() {
    // Child child1;
    // child1.show();        // child class show\

    Child child1;
    Parent *ptr;             // this pointer points to a Parent class

    ptr = &child1; // runtime binding
    ptr->hello();

/*  Function Overloading = Compiletime Polymorphism
    Function Overriding = Runtime Polymorphism
*/
    return 0;
}