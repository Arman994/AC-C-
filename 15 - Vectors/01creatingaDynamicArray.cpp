#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;

    int *arr = new int[size];     //with new we can allocate new memory needs to be deleted

    int x=1;
    for(int i=0; i<size; i++) {
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    cout << endl;
    
    // delete arr;    very important
    return 0;
}