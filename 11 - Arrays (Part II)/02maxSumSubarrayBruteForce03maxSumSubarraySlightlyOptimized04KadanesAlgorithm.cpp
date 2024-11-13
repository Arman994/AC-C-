#include <iostream>
using namespace std;

void maxSubarraySum1(int *arr, int n) {          // O(n^3)
    int maxSum = INT_MIN;

    for(int start=0; start<n; start++) {
        for(int end=start; end<n; end++) {
            int currSum = 0;
            for(int i=start; i<=end; i++) {
                currSum += arr[i];
            }
            cout << currSum << ",";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
        
    }
    cout << "The maxisum subarray sum = " << maxSum << endl;
}

void maxSubarraySum2(int *arr, int n) {
    int maxSum = INT_MIN;

    for(int start=0; start<n; start++) {         //   O(n^2)
        int currSum = 0;
        for(int end=start; end<n; end++) {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
        
    }
    cout << "The maxisum subarray sum = " << maxSum << endl;
}

void maxSubarraySum3(int *arr, int n) {
    int maxSum = INT_MIN;
    int currSum = 0;
    
    for(int i=0; i<n; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    cout << "The maxisum subarray sum = " << maxSum << endl;
}

int main () {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);

    maxSubarraySum3(arr, n);

}