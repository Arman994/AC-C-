#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int> arr, int target, int i) {
    if(i == arr.size()) {
        return -1;
    }
    if(arr[i] == target) {
        return i;
    }

    return firstOccur(arr, target, i+1);
}

int lastOccur(vector<int> arr, int target, int i) {        // very tricky
    if(i == arr.size()) {
        return -1;
    }

    int idxFound = lastOccur(arr, target, i+1);
    if(idxFound == -1 && arr[i] == target) {
        return i;
    }

    return idxFound;
}

int main() {
    vector<int > arr = {1, 2, 3, 3, 3, 4};
    cout << firstOccur(arr, 3, 0) << endl;
    cout << lastOccur(arr, 3, 0) << endl;
    return 0;
}