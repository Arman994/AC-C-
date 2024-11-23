#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) { //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node(); //insert
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string key) { //O(L)
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return temp->endOfWord;
    }

    bool startsWith(string key) {
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children[key[i]]) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    
    Trie trie;
    for(int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }
    
    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("moon") << endl;
    return 0;
}