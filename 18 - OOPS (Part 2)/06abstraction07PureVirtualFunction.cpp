#include <iostream>
using namespace std;

//abstract class
class Shape {
public:
    // void draw() // Pure virtual function

    virtual void draw() = 0;//abstract funx, pure virtual fnx
};

class Circle : public Shape {
public:
    void draw() {
        cout << "draw circle\n";
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "draw square\n";
    }
};

int main() {
    Circle cir1;
    cir1.draw();

    Square squ1;
    squ1.draw();

    // Shape sha1;
    // sha1.draw();          // shows error

    return 0;
}