#include <iostream>
using namespace std;

void removeDuplicates(string str, string ans, int map[26], int i) {
    if(i == str.size()) {
        cout << "ans : " << ans << endl;
        return;
    }

    int mapIdx = (int)(str[i] - 'a'); //typecasting

    if(map[mapIdx]) { //duplicate
        removeDuplicates(str, ans, map, i+1);
    }else { //not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ans+str[i], map, i+1);// ans = ans + str[i]
    }
}

void removeDuplicates(string str, string ans, int map[26]) {
    if(str.size() == 0) {
        cout << "ans : " << ans << endl;
        return;
    }

    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int)(str[n-1] - 'a');
    str = str.substr(0, n-1);


    if(map[mapIdx]) { //duplicate
        removeDuplicates(str, ans, map);
    }else { //not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ch+ans, map);// ch+ans -> order matters if it was ans+ch then output = orpeus
    }
}

int main() {
    string str = "superpro";
    string ans = "";
    int map[26] = {false};

    // removeDuplicates(str, ans, map, 0);
    removeDuplicates(str, ans, map);
    return 0; 
}