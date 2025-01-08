#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cmath>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;

    ll ans = 0;

    for(ll i=5; i<=n; i*=5) {
        ans += n/i;
    }

    cout << ans;
}

int main() {
    solve();
    return 0;
}
