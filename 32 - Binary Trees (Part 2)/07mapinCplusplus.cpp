#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "Ishmam";
    m[110] = "Himel";
    m[131] = "Jami";

    cout << m[101] << endl;

    m[101] = "Syed";
    cout << m[101] << endl;

    cout << m.count(101) << endl; //1
    cout << m.count(102) << endl; //0

    for(auto it : m) {
        cout << "key = " << it.first << ", " << "value = " << it.second << endl;
    }
    return 0;
}