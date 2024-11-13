#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid+1; //start of righthalf

    while(i <= mid && j <= ei) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i++]);
    }

    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    //vector -> org arr
    for(int idx=si, x=0; idx<=ei; idx++) { //org arr
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei) { //O(nlogn)
    if(si >= ei) {
        return;
    }

    int mid = si + (ei - si)/2;

    mergeSort(arr, si, mid); //lefthalf
    mergeSort(arr, mid+1, ei); //righthalf

    merge(arr, si, mid, ei); //conquer
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {5, 6, 4, 2, 3, 1};
    int n = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}