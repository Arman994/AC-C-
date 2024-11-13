#include <iostream>
using namespace std;

// void counter() {
//     // int count = 0; // prints 1 3 times

//     static int count = 0;
//     count++;
//     cout << "count : " << count << endl;
// }

class Example {
public:
    static int x;  // must be a const in class

};

int Example::x = 0;// needs to be written outside the class

int main() {

    // counter();
    // counter();
    // counter();

    Example eg1;
    Example eg2;
    Example eg3;
    cout << eg1.x++ << endl;
    cout << eg2.x++ << endl;
    cout << eg3.x++ << endl;

    return 0; 
}