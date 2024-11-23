#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connectNRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); //O(n)
    int cost = 0;

    while(pq.size() > 1) {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += min1 + min2;
        pq.push(min1 + min2);
    }

    cout << "min cost is = " << cost << endl;
    return cost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    connectNRopes(ropes);

    return 0;
}