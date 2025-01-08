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

    ll tot_sum = ((n*n) + n) / 2;

    if(tot_sum % 2 == 1) {
        cout << "NO";
        return;
    }

    vector<int> set1, set2;
    ll target_sum = tot_sum / 2;

    for(int i=n; i>=1; i--) {
        if(i<= target_sum) {
            set1.push_back(i);
            target_sum -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << "YES\n";
    cout << set1.size() << endl;

    for(int el : set1) {
        cout << el << " ";
    }

    cout << endl << set2.size() << endl;

    for(int el : set2) {
        cout << el << " ";
    }
}

int main() {
    solve();
    return 0;
}
