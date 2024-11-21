#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    m["Bangladesh"] = 20;
    m["China"] = 150;
    m["US"] = 50;
    m["India"] = 150;
    m["Nepal"] = 2;
    m["Nepal"] = 5; //gets overritten
    m.erase("India");

    cout << m["Bangladesh"] << endl;

    for(pair<string, int> country : m) {
        cout << country.first << ", " << country.second << endl; //in ordered order
    }

    if(m.count("Bangladesh")) {
        cout << "Bangladesh exists\n";
    }
    return 0;
}