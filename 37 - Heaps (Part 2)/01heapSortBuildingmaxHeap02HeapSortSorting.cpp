#include <iostream>
#include <string>
#include <queue>
using namespace std;

void heapify(int i, vector<int> &arr, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && arr[left] > arr[maxI]) { //for descending <
        maxI = left;
    }

    if(right < n && arr[right] > arr[maxI]) { //for descending <. only this two changes need to be done for descending
        maxI = right;
    }

    if(maxI != i) {
        swap(arr[i], arr[maxI]);
        heapify(maxI, arr, n);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    
    //step1 : build maxHeap
    for(int i=n/2-1; i>=0; i--) { //O(n*logn)
        heapify(i, arr, n);
    }

    //step2 : taking els to correct pos
    for(int i=n-1; i>=0; i--) { //O(n*logn)
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    heapSort(arr);

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}