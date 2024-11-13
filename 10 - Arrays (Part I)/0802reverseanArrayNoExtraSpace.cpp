#include <iostream>
using namespace std;

void printArray(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int n = sizeof(arr)/ sizeof(int);

    int start = 0;
    int end = n-1;

    while(start < end) {
        
        // swap(arr[start], arr[end]);              //   with swap function
        int temp = arr[start];                      //   manual swaping
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printArray(arr, n);

}