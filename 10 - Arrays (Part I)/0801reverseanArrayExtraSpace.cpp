#include <iostream>
using namespace std;

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr)/ sizeof(int);            // Can't do this inside a function that's why we have to use size as a parameter in functions 

    int copyArr[n];

    for(int i=0; i<n; i++) {
        int j = n - i - 1;
        copyArr[j] = arr[i];
    }

    for(int i=0; i<n; i++) {                     // Copy from copyArr to the original Arr
        arr[i] = copyArr[i];
    }

    printArray(arr, n);
} 