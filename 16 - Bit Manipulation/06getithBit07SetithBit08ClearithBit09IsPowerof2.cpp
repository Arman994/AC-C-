#include <iostream>
using namespace std;

int getIthBit(int num, int i) {
    int bitMast = 1 << i;
    if(num & bitMast) {
        return 1;
    }else {
        return 0;
    }
}

int setIthBit(int num, int i) {   //   1 in position of 0/1
    int bitMask = 1 << i;
    return num | bitMask;
}

int clearIthBit(int num, int i) { //   0 in postition of 0/1
    int bitMask = ~(1 << i);
    return num & bitMask;
}

bool isPowerOf2(int num) {
    if(!(num & (num - 1))) { //   ex : 32 = 100000 and 31 = 011111 so & would be 0
        return true;
    }else {
        return false;
    }
}

int main() {
    cout << getIthBit(6, 2) << endl;
    cout << setIthBit(6, 3) << endl;
    cout << clearIthBit(6, 1) << endl;
    cout << isPowerOf2(16) << endl;
    cout << isPowerOf2(13) << endl;

}