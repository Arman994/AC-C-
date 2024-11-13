#include <iostream>
using namespace std;

void updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i);   //   clear ith bit

    num = num | (val << i);

    cout << num << endl;
}

void clearIBits(int num, int i) {
    int bitMask = ~0 << i;
    num = num & bitMask;

    cout << num << endl;
}

int countSetBits(int num) {
    int count = 0;
    while(num>0) {
        int lastDig = num & 1;
        count += lastDig;
        num = num >> 1;      //   only num >> 1 doesn't work note that
    }
    cout << count << endl;
    return count;
}

int main() {
    
    updateIthBit(7, 3, 1);
    clearIBits(7, 2);
    countSetBits(10);
    return 0;
}