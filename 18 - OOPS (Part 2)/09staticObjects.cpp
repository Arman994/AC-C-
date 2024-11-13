#include <iostream>
using namespace std;

class Example {
public:
    Example() {
        cout << "constructor..\n";
    }
    
    ~Example() {
        cout << "destructor..\n";
    }
};
int main() {
    int a = 0;
    if(a == 0) {
        // Example eg1;//constructor..destructor..code ending..
        static Example eg1;
    }

    cout << "code ending..\n";
    return 0;
}