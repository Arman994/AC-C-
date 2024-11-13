#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int si, int ei) {
    int i = si-1;
    int pivot = arr[ei];

    for(int j=si; j<ei; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);
    
    //pivotIdx = i
    return i;
}

void quickSort(int arr[], int si, int ei) { //O(nlogn) but worst case O(n^2)
    if(si >= ei) {
        return;
    }

    int pivotIdx = partition(arr, si, ei);

    quickSort(arr, si, pivotIdx-1); //lefthalf
    quickSort(arr, pivotIdx+1, ei); //righthalf
}

int main() {
    int arr[6] = {5, 6, 4, 2, 3, 1};
    int n = sizeof(arr)/sizeof(int);

    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}