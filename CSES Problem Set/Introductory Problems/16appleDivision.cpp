#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    long long totalWeight = 0;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        totalWeight += weights[i];
    }

    long long minDifference = LLONG_MAX;

    // Generate all subsets using bitmasking
    for (int mask = 0; mask < (1 << n); mask++) {
        long long group1Weight = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1Weight += weights[i];
            }
        }

        long long group2Weight = totalWeight - group1Weight;
        long long difference = abs(group1Weight - group2Weight);
        minDifference = min(minDifference, difference);
    }

    cout << minDifference << endl;
    return 0;
}
