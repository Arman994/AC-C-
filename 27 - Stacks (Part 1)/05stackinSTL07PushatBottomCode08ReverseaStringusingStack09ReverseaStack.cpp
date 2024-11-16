#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) { //O(N); O(N)
    string ans;
    stack<char> s;

    for(int i=0; i<str.size(); i++) {
        s.push(str[i]);
    }

    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    return ans; 
}

void pushAtBottom(stack<int> &s, int val) { //all STL are passed by value. So we have to pass it by reference manually.
    if(s.empty()) {
        s.push(val); //push at top = push at bottom
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);
}

void reverse(stack<int> &s) { //if not passed by reference original stack won't be changed at all
    if(s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s) {
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    pushAtBottom(s, 4);
    printStack(s);

    string str = "Superpro";
    cout << "reverse = " << reverseString(str) << endl;
    
    reverse(s);
    printStack(s);
    return 0;
}