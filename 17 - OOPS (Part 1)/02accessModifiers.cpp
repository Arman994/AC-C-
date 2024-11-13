#include <iostream>
using namespace std;

class Student {
private: //if not written then implicitely will be priven until public
    string name;
public:
    float cgpa;

    void getPercentage() {
        cout << (cgpa * 20) << "% \n";
    }
};


int main() {
    Student s1;
    // s1.name = "Superpro";
    s1.cgpa = 4.0;
    // cout << s1.name << endl;
    cout << s1.cgpa << endl;
    s1.getPercentage();

}