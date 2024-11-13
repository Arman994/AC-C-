#include <iostream>          // generaly used when the difference between max and min in an array is low
using namespace std;

void countingSort(int arr[], int n) {
    int freq[100000];
    int minVal=INT_MAX, maxVal=INT_MIN;

    //1st step
    for(int i=0; i<n; i++) {
        freq[arr[i]]++;
        minVal = min(arr[i], minVal);
        maxVal = max(arr[i], maxVal);
    }
    //2nd step
    for(int i=minVal, j=0; i<=maxVal; i++) {
        while(freq[i]>0) {
            arr[j++] = i;
            freq[i]--;
            // j++;
            // freq[i]--;
        } 
    }
}

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    int arr[8] = {7, 4, 1, 3, 2, 1, 1, 1};
    int n = sizeof(arr)/sizeof(int);

    countingSort(arr, n);

    printArray(arr, n);
}