#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;

    for(ll i=1; i<=n; i++) {
        ll total_combinations, attacking_knights;
        total_combinations = ((i * i) * ((i * i) - 1)) / 2;
        attacking_knights = 2 * 2 * (i-1) * (i-2);

        cout << total_combinations - attacking_knights << endl;
    }
}

int main() {
    solve();
    return 0;
}
