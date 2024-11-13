#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    char charStr[25];
    cin.getline(charStr, 25, '.');     //   means with . getline will be terminated

    cout<< charStr << endl;

    string str;
    getline(cin, str, '.');   //   means with . getline will be terminated
    
    for(char ch : str) {
        cout << ch;
    }
}