#include <iostream>
using namespace std;

void fastExpo(int x, int n) {
    int ans = 1;
    while(x>0) {
        int lastDig = n & 1;
        if(lastDig) {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;          //   only n >> 1 doesn't work note that
    }
    cout << ans << endl;

}

int main() {
    fastExpo(3, 5);

}