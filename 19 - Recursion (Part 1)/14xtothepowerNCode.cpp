#include <iostream>
using namespace std;

int pow(int x, int n) {
    if(n == 0) {
        return 1;
    }

    int halfPow = pow(x, n/2);
    int halfPowSquare = halfPow * halfPow;

    if(n & 1) {//odd
        return x * halfPowSquare;
    }
    return halfPowSquare;
}

int main() {
    cout << pow(2, 5) << endl;
    return 0;
}