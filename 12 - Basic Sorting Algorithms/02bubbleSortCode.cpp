#include <iostream>
using namespace std;

void bubbleSort (int arr[], int n) {
    for(int i=0; i<n-1; i++) {                   //   i<n-1
        
        bool isSwap = false;

        for(int j=0; j<n-i-1; j++) {             //   j<n-i-1

            if(arr[j] > arr[j+1]) {              //   for descending order just change > to <
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            // Array is already sorted
            return;
        }
    }
}

// void bubbleSort(int *arr, int n) {
//     for(int i=0; i<n-1; i++) {                   //   i<n-1

//         for(int j=0; j< n-i-1; j++) {            //   j<n-i-1

//             if(arr[j] > arr[j+1])                //   for descending order just change > to <
//             swap(arr[j], arr[j+1]);
//         }
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

    bubbleSort(arr, n);

    printArray(arr, n);
}