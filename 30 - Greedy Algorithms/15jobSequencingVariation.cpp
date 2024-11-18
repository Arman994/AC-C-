// Also store the index of jobs that are done

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) { // cause we are using job object we have to rename this to pairs
    int n = pairs.size();
    vector<Job> jobs;

    for(int i=0; i<n; i++) {
        // jobs.push_back(new Job()) // we had to create a totally new object in push_back and then we had to pass the values in to that obj
    
        jobs.emplace_back(i, pairs[i].first, pairs[i].second); // we use emplace_back whenever we need to use vector of objects
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) { // [] -> capture list. (lamda function) which has no name just parameter and use. No one can call this function it is basically used for single use.
        return a.profit > b.profit;
    }); // Note -> the lamda function is totally whithin the sort function look at the syntax. This is used instead of compare function and it's written in here cause it is used for single use. All compare functions can be written like this as a lamda function.

    cout << "selecting the job" << jobs[0].idx << endl; // can't say this is 0th job
    int profit = jobs[0].profit; // we are using the object
    int safeDeadline = 2;

    for(int i=1; i<n; i++) {
        if(jobs[i].deadline >= safeDeadline) {
            cout << "selecting the job" << jobs[i].idx << endl; // can't say this is 0th job
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }

    cout << "max profit = " << profit << endl;
    return profit;
}

int main() {
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);

    return 0;
}