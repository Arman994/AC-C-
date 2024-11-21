//works exactly as unordered map just stores only key no values

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(6);
    s.insert(4);
    
    cout << s.size() << endl;
    s.insert(1); //duplicates don't get stored
    s.insert(1);
    s.insert(1);
    cout << s.size() << endl;

    s.erase(3);
    if(s.find(3) != s.end()) {
        cout << "3 exists\n";
    } else {
        cout << "3 doesn't exists\n";
    }

    for(auto el : s) {
        cout << el << " ";
    }
    return 0;
}