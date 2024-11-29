#include <iostream>
#include <vector>
using namespace std;

int mcmRec(vector<int> arr, int i, int j) { //return minCost
    if(i == j) {
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++) {
        //(i, k)
        int cost1 = mcmRec(arr, i, k);

        //(k+1, j)
        int cost2 = mcmRec(arr, k+1, j);

        int currCost = cost1 + cost2 + arr[i-1] * arr[k] * arr[j];
        ans = min(ans, currCost);
    }

    return ans;
}

int mcmMem(vector<int> arr, int i, int j, vector<vector<int>> &dp) { //return minCost
    if(i == j) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++) {
        //(i, k)
        int cost1 = mcmMem(arr, i, k, dp);

        //(k+1, j)
        int cost2 = mcmMem(arr, k+1, j, dp);

        int currCost = cost1 + cost2 + arr[i-1] * arr[k] * arr[j];
        ans = min(ans, currCost);
    }

    return dp[i][j] = ans;
}

int mcmTab(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    //initialization
    for(int i=0; i<n; i++) {
        dp[i][i] = 0;
    }

    //bottom up fill
    for(int len=2; len<n; len++) {
        for(int i=1; i<=n-len; i++) {
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<j; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[1][n-1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3}; //n -> n-1 matrices (1 to n-1)
    int n = arr.size();

    cout << mcmRec(arr, 1, n-1) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << mcmMem(arr, 1, n-1, dp) << endl;

    cout << mcmTab(arr) << endl;
    return 0;
}