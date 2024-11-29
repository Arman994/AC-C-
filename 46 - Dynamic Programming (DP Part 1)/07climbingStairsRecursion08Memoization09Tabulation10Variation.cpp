#include <iostream>
#include <vector>
using namespace std;

//Count ways to reach the nth stair. A person can climb 1 or 2 stairs at a time
int countWaysRec(int n) { //O(2^n)
    if(n == 0 || n == 1) {
        return 1;
    }

    return countWaysRec(n-1) + countWaysRec(n-2);
}

int countWaysMem(int n, vector<int> &dp) {
    if(n == 0 || n == 1) {
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = countWaysMem(n-1, dp) + countWaysMem(n-2, dp);
    return dp[n];
}

int countWaysTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int countWaysVar(int n) { //variation 1, 2 & 3 jumps allowed
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main() {
    int n = 6;
    vector<int> dp(n+1, -1);

    cout << countWaysRec(n) << endl;
    cout << countWaysMem(n, dp) << endl;
    cout << countWaysTab(n) << endl;
    cout << countWaysVar(n) << endl;
    return 0;
}