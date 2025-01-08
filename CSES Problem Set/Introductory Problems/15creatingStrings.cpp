#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Sort the string to ensure lexicographical order
    sort(s.begin(), s.end());

    set<string> permutations;

    // Generate all permutations using next_permutation
    do {
        permutations.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    // Output the results
    cout << permutations.size() << endl;
    for (const auto &str : permutations) {
        cout << str << endl;
    }

    return 0;
}
