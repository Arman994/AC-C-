#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool comp(int a, int b) { //this works the same
//     return a < b;
// }

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second; //ascending - end
    // return p1.second > p2.second; //descending - end

    // return p1.first < p2.first; //ascending - start
    // return p1.first > p2.first //descending - start
}

int main() {
    vector<int> start = {0, 1, 2};
    vector<int> end = {9, 2, 4};

    vector<pair<int, int>> activity(3, make_pair(0, 0)); //size = 3 and initialized with (0, 0) value

    activity[0] = make_pair(0, 9);
    activity[1] = make_pair(1, 2);
    activity[2] = make_pair(2, 4);

    for(int i=0; i<activity.size(); i++) {
        cout << "A" << i << " : "<< activity[i].first << ", " << activity[i].second << endl;
    }

    sort(activity.begin(), activity.end(), compare); //O(nlogn) compare function determines how sorting is going to work
    
    cout << "--------sorted--------\n";
    for(int i=0; i<activity.size(); i++) {
        cout << "A" << i << " : "<< activity[i].first << ", " << activity[i].second << endl;
    }
    return 0;
}