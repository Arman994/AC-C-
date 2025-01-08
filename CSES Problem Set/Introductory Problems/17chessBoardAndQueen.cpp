#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <numeric>
using namespace std;

string s[8]; // Chessboard representation
bool b[15];  // Array for tracking diagonal and column usage

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> s[i];  // Input the chessboard layout
    }

    int p[8], ans = 0;
    iota(p, p + 8, 0);  // Initialize the permutation array

    do {
        bool ok = 1;
        
        // Check if the queen placement on row i is valid (i.e., it must be on a free square)
        for (int i = 0; i < 8; i++) {
            ok &= s[i][p[i]] == '.';  // Check if the queen can be placed in this square
        }

        if (!ok) continue; // If any invalid placement is found, skip this permutation
        
        memset(b, 0, sizeof(b)); // Reset the diagonal and column usage array

        // Check for column clashes (we can't place more than one queen in any column)
        for (int i = 0; i < 8; i++) {
            if (b[i + p[i]]) {
                ok = 0; // If column clash, it's not a valid placement
            }
            b[i + p[i]] = 1;  // Mark this column as occupied
        }

        if (!ok) continue; // If there was a column clash, skip this permutation

        memset(b, 0, sizeof(b)); // Reset the diagonal usage array again

        // Check for diagonal clashes (we can't place more than one queen on the same diagonal)
        for (int i = 0; i < 8; i++) {
            if (b[i + 7 - p[i]]) {
                ok = 0; // If diagonal clash, it's not a valid placement
            }
            b[i + 7 - p[i]] = 1;  // Mark this diagonal as occupied
        }

        if (ok) {
            ans++; // If no clashes, increment the number of valid solutions
        }

    } while (next_permutation(p, p + 8)); // Generate all permutations of the queen positions

    cout << ans << endl; // Output the number of valid solutions
}
