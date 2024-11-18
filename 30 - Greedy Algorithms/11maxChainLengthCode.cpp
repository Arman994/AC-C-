#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maxChainLenth(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    int count = 1;
    int currEnd = pairs[0].second;

    for(int i=1; i<n; i++) {
        if(pairs[i].first > currEnd) { //can't use pairs[i-1].second instead of currEnd cause everytime the currEnd will not be the previous pairs second value
            count++;
            currEnd = pairs[i].second;
        }
    }
    cout << "max chain lenth = " << count << endl;
    return count;
}

int main() {
    int n = 5;
    vector<pair<int, int>> pairs(n, make_pair(0, 0));
    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);
    
    maxChainLenth(pairs); 
    return 0;
}