#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str) {
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if(s.empty()) {
                return false;
            }

            char top = s.top();
            if((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

bool isDuplicate(string str) {
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch != ')') { //non-closing
            s.push(ch);
        } else { //closing
            if(s.top() == '(') { //DUPLICATE
                return true; //true means duplicate
            }

            while(s.top() != '(') {
                s.pop();
            }
            s.pop();
        }
    }

    return false;
}

int main() {
    string t = "[{()}]";
    string f = "{)([])}";

    cout << isValid(t) << endl;
    cout << isValid(f) << endl;

    string dupt =   "((a+b))"; //valid : true 
    string dupf = "((a+b)+(c+d))"; //invalid : false

    cout << isDuplicate(dupt) << endl;
    cout << isDuplicate(dupf) << endl;

    return 0;
}