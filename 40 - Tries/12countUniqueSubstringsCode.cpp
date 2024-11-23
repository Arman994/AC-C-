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

    void insert(string key) { // O(L)
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            if (!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node(); // insert
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    int countNodes(Node* node) { // DFS to count nodes
        if(!node) {
            return 0;
        }

        int count = 1; // Count current node
        for(auto& child : node->children) {
           
            count += countNodes(child.second); // Add counts of children
        }
        return count;
    }

    int countUniqueSubstrings() {
        return countNodes(root) - 1; // Subtract 1 to exclude the root node
    }
};

int countUniqueSubstringOfAString(string key) {
    Trie trie;

    // Insert all suffixes of the string into the Trie
    for (int i = 0; i < key.size(); i++) {
        trie.insert(key.substr(i));
    }

    // Count the unique substrings
    return trie.countUniqueSubstrings() + 1; // we have to count empty substring too.
}

int main() {
    string key = "abab";
    cout << "The number of unique substrings in \"" << key << "\" is: " 
         << countUniqueSubstringOfAString(key) << endl;

    return 0;
}
