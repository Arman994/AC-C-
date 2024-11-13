//Find & print all permutations (arrangements) of a given string

#include <iostream>
#include <string>
using namespace std;

void permutations(string str, string ans) {
    int n = str.size();
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    for(int i=0; i<n; i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);
        permutations(nextStr, ans + ch); //ith char choice to add in perm
    }
}

int main() {
    string str = "superduoerori";
    string ans = "";

    permutations(str, ans);
    return 0;
}