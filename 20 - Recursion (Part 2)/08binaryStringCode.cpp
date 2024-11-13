// Print all Binary strings of size N without any consecutive 1s.

#include <iostream>
using namespace std;

void binString(int n, int lastPlace, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }
    if(lastPlace != 1) {
        binString(n-1, 0, ans + '0');
        binString(n-1, 1, ans + '1');
    }else {
        binString(n-1, 0, ans + '0');  
    }
}

void binString(int n, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }
    if(ans[ans.size() - 1] != '1') {   // this has to be a char 1 = '1' and can't use == 0 condition
        binString(n-1, ans + '0');
        binString(n-1, ans + '1');
    }else {
        binString(n-1, ans + '0');  
    }
}

int main() {
    string ans = "";
    binString(3, ans);
    binString(3, 0, ans);
    return 0;
}