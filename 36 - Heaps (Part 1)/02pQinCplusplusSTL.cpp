#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);

    while(!pq.empty()) {
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<int>> pq2; //container then a custom compare

    pq2.push(5);
    pq2.push(10);
    pq2.push(9);
    pq2.push(7);
    pq2.push(3);

    cout << "now ascendingly-----------" << endl;
    while(!pq2.empty()) {
        cout << "top : " << pq2.top() << endl;
        pq2.pop();
    }
    
    priority_queue<string> pqs;

    pqs.push("SuperPro");
    pqs.push("Mahdy Nesar Mahy");
    pqs.push("Adnan Hussein jami");
    pqs.push("Arman Nesar Samy");
    pqs.push("Ibrahim Khalilullah");

    while(!pqs.empty()) {
        cout << "top : " << pqs.top() << endl;
        pqs.pop();
    }

    priority_queue<string, vector<string>, greater<string>> pqs2; 

    pqs2.push("SuperPro");
    pqs2.push("Mahdy Nesar Mahy");
    pqs2.push("Adnan Hussein jami");
    pqs2.push("Arman Nesar Samy");
    pqs2.push("Ibrahim Khalilullah");

    cout << "now ascendingly-----------" << endl;
    while(!pqs2.empty()) {
        cout << "top : " << pqs2.top() << endl;
        pqs2.pop();
    }
    return 0;
}