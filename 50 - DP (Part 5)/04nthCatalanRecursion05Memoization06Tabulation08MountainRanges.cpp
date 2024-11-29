#include <iostream>
#include <vector>
using namespace std;

int catalanRec(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += catalanRec(i) * catalanRec(n-i-1);
    }

    return ans;
}

int catalanMem(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        ans += catalanMem(i, dp) * catalanMem(n-i-1, dp);
    }

    return dp[n] = ans;
}

int catalanTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<n+1; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int mountainRanges(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<n+1; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}

int main() {
    for(int i=0; i<=6; i++) {
        cout << catalanRec(i) << " ";
    }
    cout << endl;

    int n = 6;
    vector<int> dp(n+1, -1);
    cout << catalanMem(n, dp) << endl;

    cout << catalanTab(n) << endl;

    cout << mountainRanges(3) << endl;
    return 0;
}