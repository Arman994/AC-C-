#include <iostream>
using namespace std;

void printSubarray(int *arr, int n) {            //   time complexity big O(n^3)
    for(int start=0; start<n; start++) {
        for (int end=start; end<n; end++) {
            // cout << "(" << start << ", " << end << ") ";

            for(int i=start; i<=end; i++) {
                cout << arr[i];
            }
            cout << ", ";
        }
    }
}

int main () {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    printSubarray(arr, n);
}