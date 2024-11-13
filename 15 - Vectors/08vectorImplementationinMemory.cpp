#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> vec = {1, 2, 3, 4};   //   vec(10, -1) means size 10 and initialized with -1
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;

    vec.push_back(5);    
    cout << "size : " << vec.size() << endl; //5
    cout << "capacity : " << vec.capacity() << endl; // 8  generally it takes O(n) but we can consider it linear becauase of average/ammortized time complexity so O(1)

// for delete we use vec.pop_back()
} 