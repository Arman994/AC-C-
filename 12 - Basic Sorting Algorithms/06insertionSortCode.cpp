#include <iostream>          //   have sorted and unsorted 2 arrays pick an element from unsorted array and put it at the right place in the sorted array
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;

    }
}

// void insertionSort(int arr[], int n) {
//     for(int i=1; i<n; i++) {
//         int curr = arr[i];
//         int j = i-1;

//         for(; j>=0; j--) {
//             if(arr[j] > curr) {
//                 swap(arr[j+1], arr[j]);
//             }
//             else{
//                 break;
//             }
//         }
//         arr[j+1] = curr;

//     }
// }


void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    int arr[5] = {5, 4, 1, 3, 2};
    int n = sizeof(arr)/sizeof(int);

    insertionSort(arr, n);

    printArray(arr, n);
}