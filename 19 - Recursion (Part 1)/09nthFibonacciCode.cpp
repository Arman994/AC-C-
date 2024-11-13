#include <iostream>
using namespace std;

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n; //0, 1
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cout << fibonacci(8) << endl;
    return 0;
}