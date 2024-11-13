// Find number of ways to reach from (0,0) to (N-1, M-1) in a NxM Grid. Allowed moves - right or down      TC = O(2^(n+m))

#include <iostream>
using namespace std;

int gridWays(int row, int col, int n, int m, string ans) {
    if(row == n-1 && col == m-1) { 
        cout << ans << " \n";
        return 1;
    }

    if(row >= n || col >= m) {
        return 0;
    }

    //right
    int val1 = gridWays(row, col+1, n, m, ans+'R');

    //down
    int val2 = gridWays(row+1, col, n, m, ans+'D');

    return val1 + val2;
}

int main() {
    int n = 3;
    int m = 3;
    string ans = "";

    cout << gridWays(0, 0, n, m, ans) << endl;
    return 0;
}