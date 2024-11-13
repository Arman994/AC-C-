// Find total ways in which n friends can be paired up. Each friend can only be paired once.

#include <iostream>
using namespace std;

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    return friendsPairing(n-1) + (n-1)*friendsPairing(n-2); //for each person pairing option is n-1
}

int main() {
    cout << friendsPairing(4) << endl;
    return 0;
}