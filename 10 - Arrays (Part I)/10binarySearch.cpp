#include <iostream>
using namespace std;

int binerySearch(int *arr, int n, int key) {
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;

    while(start <= end) {                        //   <= is used in main binerySearch cause what if the element is at 5 and start and end both are at index 5
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }

    return -1;                                   //   means key is not found
}

int main() {
    int arr[] = {1, 3 , 5 , 7, 9, 11, 13, 15};
    int n = sizeof(arr)/sizeof(int);

    cout << binerySearch(arr, n, 11) << endl;


}