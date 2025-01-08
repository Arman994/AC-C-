#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
void solve() {
    string str;
    cin >> str;
 
    int count[26] = {0};
 
    for(char ch : str) {
        count[ch - 'A']++;
    }
 
    string left_half = "", right_half = "", middle = "";
 
    for(int i=0; i<26; i++) {
        if(count[i]%2 == 1) {
            if(str.size()%2 == 0) {
                cout << "NO SOLUTION\n";
                return;
            } else {
                if(middle == "") {
                    middle = i + 'A';
                    count[i]--;
                } else {
                    cout << "NO SOLUTION\n";
                    return;
                }
            }
        }
 
        left_half += string(count[i]/2, i + 'A');
    }
 
    right_half = left_half;
 
    reverse(right_half.begin(), right_half.end());
 
    cout << left_half + middle + right_half << endl;
}
 
int main() {
    solve();
    return 0;
}