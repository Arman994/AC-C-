#include <iostream>
#include <vector>
using namespace std;

template<class T> //template

class Stack {
    vector<T> vec;
public:
    void push(T val) { //O(1)
        vec.push_back(val);
    }

    void pop() { //O(1)
        if(isEmpty()) {
            cout << "stack is empty.\n";
            return;
        }
        vec.pop_back();
    }

    T top() { //O(1)
        // if(isEmpty()) {
        //     cout << "stack is empty.\n";
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main() { 
    Stack<string> s;

    s.push("superpro");
    s.push("a");
    s.push("be");

    while(!s.isEmpty()) {
        cout << s.top() << " "; //LIFO
        s.pop();
    }
    cout << endl;

    return 0;
}