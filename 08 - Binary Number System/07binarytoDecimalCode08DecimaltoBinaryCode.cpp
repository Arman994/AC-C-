#include <iostream>
using namespace std;

void binToDec(int binNum) {
    int n = binNum;
    int decNum = 0;
    int pow = 1; // 2^0, 2^1,2^2;
    while(n > 0) {
        int lastDig = n % 10;
        decNum += lastDig * pow;
        pow *= 2;
        n /= 10;
    }

    cout << decNum << endl;
}

void decToBin(int decNum) {
    int n = decNum;
    int binNum = 0;
    int pow = 10; // 10^0, 10^1,10^2;

    while(n>0) {
        int rem = n % 2;
        binNum += rem * pow;
        n /= 2;
        pow *= 10;
    }

    cout << binNum << endl;    
}

int main() {
    binToDec(101);
    decToBin(32);
}