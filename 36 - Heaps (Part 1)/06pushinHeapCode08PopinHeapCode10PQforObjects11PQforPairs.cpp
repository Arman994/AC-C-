#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Heap {
    vector<int> vec; //max heap
public:

    void push(int val) { //O(logn)
        //step1
        vec.push_back(val);

        //fix heap
        int x = vec.size()-1; //childI
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]) { 
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int i) { //i = parI
        if(i >= vec.size()) {
            return;
        }

        int l = 2*i + 1;
        int r = 2*i + 2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }
        
        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i) { //swapping with child node
            heapify(maxIdx);
        }
    }

    void pop() {
        //step1
        swap(vec[0], vec[vec.size()-1]);

        //step2
        vec.pop_back();

        //step3
        heapify(0); //O(logn)
    }

    int top() { //O(1)
        return vec[0]; //highest priotity element
    }

    bool empty() {
        return vec.size() == 0;
    }
};

class Student { //"<" overload
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // bool operator < (const Student &obj) const { //max heap
    //     return this->marks < obj.marks;
    // }

    bool operator < (const Student &obj) const { //min heap
        return this->marks > obj.marks;
    }
};

struct Comparepair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) { // maxHeap based on second property
        return p1.second < p2.second;
    }
};

// struct Comparepair {
//     bool operator () (pair<string, int> &p1, pair<string, int> &p2) { // minHeap basen on second property
//         return p1.second > p2.second; 
//     }
// };

int main() {
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    while(!heap.empty()) {
        cout << "top = " << heap.top() << endl;
        heap.pop();
    }

    priority_queue<Student> pq; //default - maxHeap; "first"
    pq.push(Student("Ishmam", 96));
    pq.push(Student("Superpro", 20));
    pq.push(Student("Himel", 90));

    cout << "PQ for objects -------" << endl;
    while(!pq.empty()) {
        cout << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comparepair> ppq;

    ppq.push(make_pair("Ishmam", 95));
    ppq.push(make_pair("Superpro", 20));
    ppq.push(make_pair("Himel", 90));

    cout << "PQ for pairs -------" << endl;
    while(!ppq.empty()) {
        cout << ppq.top().first << ", " << ppq.top().second << endl;
        ppq.pop();
    }
    return 0;
}