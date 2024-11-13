#include <iostream>
using namespace std;

int search(int arr[], int si, int ei, int tar) {
    if(si > ei) {
        return -1;
    }
    
    int mid = si + (ei - si)/2;

    if(arr[mid] == tar) {
        return mid;
    }

    if(arr[si] <= arr[mid]) {
        //L1
        if(arr[si] <= tar && tar <= arr[mid]) { //logic does not change if we use tar < arr[mid] cause it isn't equal cause it's checked above
            //left half
            return search(arr, si, mid-1, tar); //because of return only one call can execute so O(logn)
        }else {
            //right half
            return search(arr, mid+1, ei, tar);
        }
    }else {
        //L2
        if(arr[mid] <= tar && tar <= arr[ei]) { //logic does not change if we use arr[mid] < tar
            //right half
            return search(arr, mid+1, ei, tar);
        }else {
            //left half
            return search(arr, si, mid-1, tar);
        }
    }
}

int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr)/sizeof(int);

    cout << "idx : " << search(arr, 0, n-1, 2) << endl; //4
    return 0;
}