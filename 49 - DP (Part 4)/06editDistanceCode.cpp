#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int j=0; j<m+1; j++) { //0th row initialize - insert
            dp[0][j] = j;
        }

        for(int i=0; i<n+1; i++) { //0th col - delete
            dp[i][0] = i;
        }

        //bottom up fill
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};