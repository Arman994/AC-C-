#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int subarrayCountWithK(vector<int> arr, int k) { //sum[i, j] = sum[j] - sum[i]
    unordered_map<int, int> m; //sum, count
    m[0] = 1; //very important logic
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size() ; j++) {
        sum += arr[j];
        
        if(m.count(sum-k)) {
            ans += m[sum-k];
        }

        if(m.count(sum)) {
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;

    vector<int> arr2 = {1, 2, 3};
    int k2 = 3;

    cout << "subarray count1 = " << subarrayCountWithK(arr, k) << endl;

    cout << "subarray count2 = " << subarrayCountWithK(arr2, k2) << endl;
    return 0;
}