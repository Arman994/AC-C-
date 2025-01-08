#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void generateGrayCode(int n) {
    int total_codes = 1 << n;
    for(int i=0; i<total_codes; i++) {
        int gray = i ^ (i >> 1);
        cout << bitset<16>(gray).to_string().substr(16-n) << endl;
    }
}

vector<string> gray(int n) {
    vector<string> res;

    if(n == 1) {
        res.push_back("0");
        res.push_back("1");
        return res;
    }

    vector<string> pre_res = gray(n-1);
    int size = pre_res.size();

    for(int i=0; i<size; i++) {
        res.push_back(pre_res[i] + "0");
    }

    for(int i=size-1; i>=0; i--) {
        res.push_back(pre_res[i] + "1");
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans = gray(n);

    for(string str : ans) {
        cout << str << endl;
    }
    return 0;
}
