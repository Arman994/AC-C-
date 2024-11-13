#include <iostream>          // Easy way to remember this - trying to find the smallest element
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {                   //   i<n-1
        int minIndex = i;

        for(int j=i+1; j<n; j++) {               //   j=i+1
            if(arr[j] < arr[minIndex]) {         //   for descending order just change > to <
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }
}

int main() {
    int arr[5] = {5, 4, 1, 3, 2};
    int n = sizeof(arr)/sizeof(int);

    selectionSort(arr, n);

    printArray(arr, n);
}