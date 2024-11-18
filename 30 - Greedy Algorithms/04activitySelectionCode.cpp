#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {
    //sort on end time. This time it is already sorted
    //A0 select
    cout << "selecting A0\n";
    int count = 1; //1st one is already selected
    int currEndTime = end[0];

    for(int i=1; i<start.size(); i++) {
        if(start[i] >= currEndTime) { //can't use pairs[i-1].second instead of currEnd cause everytime the currEnd will not be the previous pairs second value
            cout << "selecting A" << i << endl;
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9}; //4

    cout << maxActivities(start, end) << endl;
    return 0;
}