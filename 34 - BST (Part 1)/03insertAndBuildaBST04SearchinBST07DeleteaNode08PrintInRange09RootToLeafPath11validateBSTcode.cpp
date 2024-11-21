#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) { //generally there are no duplicates in BST so we don't need to consider root->data == val case.
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->data) { //left subtree
        root->left = insert(root->left, val);
    } else { //right subtree
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) { //left subtree
        return search(root->left, key);
    } else {
        return search(root->right, key); //right subtree
    }

}

Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* delNode(Node* root, int val) {
    if(root == NULL) {
        return NULL;
    }

    if(val < root->data) { //left subtree
        root->left = delNode(root->left, val);
    } else if(val > root->data) { //right subtree
        root->right = delNode(root->right, val);
    } else {
        //root == val
        //case1 : 0 child
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        }

        //case2 : 1 child
        if(root->left == NULL || root->right == NULL) {
            return root->left == NULL ? root->right : root->left;
        }

        //case3 : 2 child        here we don't need to check any condition cause if case1 and case2 didn't apply then it has to be case3
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); //case1, case2
        return root;
    }
    return root;
}

void printInRange(Node* root, int start, int end) {
    if(root == NULL) {
        return;
    }
    
    if(start <= root->data && root->data <= end) { //case1
        printInRange(root->left, start, end); //for sorting do this like inorder
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if(root->data < start) { //case2
        printInRange(root->right, start, end);
    } else { //case3       (root->data > end)
        printInRange(root->left, start, end);
    }
}

void printPath(vector<int> path) {
    cout << "path : ";
    for(int i=0; i<path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int> &path) { //path has to be passed by reference
    if(root == NULL) {
        return;
    }
    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL) {
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
}

void pathToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

bool validateHelper(Node* root, Node* min, Node* max) {
    if(root == NULL) {
        return true;
    }

    if(min != NULL && root->data < min->data) {
        return false;
    }

    if(max != NULL && root->data > max->data) {
        return false;
    }

    return validateHelper(root->left, min, root)
        && validateHelper(root->right, root, max);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7}; //1 2 3 4 5 7
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; //1 3 4 5 6 8 10 11 14

    // Node* root = buildBST(arr, 6);
    // inorder(root);
    // cout << endl;

    Node* root = buildBST(arr2, 9);
    inorder(root); 
    cout << endl;

    cout << validateBST(root) << endl;

    pathToLeafPath(root);

    printInRange(root, 5, 12);
    cout << endl;

    cout << search(root, 6) << endl;

    delNode(root, 4);
    inorder(root);
    cout << endl;
    return 0;
}