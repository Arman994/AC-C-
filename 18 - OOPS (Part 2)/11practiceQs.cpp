//Predict the output 

#include <iostream>
using namespace std;

class Parent {
public:    
    Parent() {cout << "Constructor Parent\n";}
    ~Parent() {cout << "Destructor Parent\n";}
};

class Child : public Parent {
public:
    Child() {cout << "Constructor Child\n";}
    ~Child() {cout << "Destructor Child\n";}
    
};

int main() {
    Child obj;
    return 0;
}