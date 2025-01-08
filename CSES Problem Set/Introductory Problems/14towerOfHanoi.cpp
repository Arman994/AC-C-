#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, int source, int destination, int auxiliary, vector<pair<int, int>> &moves) {
    if (n == 1) {
        // Move the only disk from source to destination
        moves.push_back({source, destination});
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination, moves);
    // Move the nth disk from source to destination
    moves.push_back({source, destination});
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source, moves);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> moves;
    towerOfHanoi(n, 1, 3, 2, moves);

    // Output the total number of moves
    cout << moves.size() << endl;
    // Output each move
    for (auto move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
