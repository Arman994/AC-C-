#include <iostream>
using namespace std;

void printArray(int *ptr, int n) {
    for(int i=0; i<n; i++) {
        cout << *(ptr + i) << "\n";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(int);

    printArray(arr, n);
}