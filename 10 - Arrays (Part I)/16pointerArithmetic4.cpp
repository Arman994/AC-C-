#include <iostream>
using namespace std;

int main() {
    // int a = 5
    int arr[20] = {1, 2, 3, 4, 5, 6, 7};
    int *ptr1 = arr;                             // arr is already an adress so no need to use &arr
    int *ptr2 = ptr1 + 3;

    cout << *ptr2 << "\n"; // 4
    cout << *ptr1 << "\n"; // 1

    cout << (ptr2 == ptr1) << "\n";              // yes : true : 1
    return 0;
}