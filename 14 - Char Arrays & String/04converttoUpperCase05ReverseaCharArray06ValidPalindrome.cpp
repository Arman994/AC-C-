#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[], int n) {
    for(int i=0; i<n; i++) {
        char ch =word[i];
        if(ch>='A' && ch<='Z') {
            continue;
        }else {
            word[i] = ch - 'a' + 'A';
        }
    }
}

void reverse(char word[], int n) {
    int start=0, end=n-1;
    while(start < end)  {              //   <= works the same but not necessary it's not a binery search so middle one don't need to be swapped
        swap(word[start], word[end]);
        start++, end--;
    }              
}

bool isPalindrome(char word[], int n) {
    int start=0, end=n-1;
    while(start < end) {               //   <= works the same but not necessary it's not a binery search so middle one don't need to be swapped
        if(word[start++] != word[end--]) {
            cout << "not valid palindrome\n";
            return false;
        }
    }
    cout << "valid palindrome\n";

    return true;
}

int main() {
    char word[] = "racecar";

    isPalindrome(word, strlen(word));

    cout << word;

}