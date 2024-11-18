#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;

Node* buildTree(vector<int> nodes) { //O(n)
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void preorder(Node* root) { //O(n)
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) { //O(n)
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) { //O(n)
    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// void levelOrder(Node* root) { //O(n); O(n)
//     if(root == NULL) {
//         return;
//     }

//     queue<Node*> Q;
//     Q.push(root);

//     while(!Q.empty()) {
//         Node* curr = Q.front();
//         Q.pop();

//         cout << curr->data << " ";

//         if(curr->left != NULL) {
//             Q.push(curr->left);
//         }

//         if(curr->right != NULL) {
//             Q.push(curr->right);
//         }
//     }

//     cout << endl;
// }

void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL) {
            cout << endl;
            if(Q.empty()) {
                break;
            }
            Q.push(NULL); //to track the next line. This concept can be used for many questions such as levelwise sum.
        } else {
            cout << curr->data << " ";
            
            if(curr->left != NULL) {
                Q.push(curr->left);
            }

            if(curr->right != NULL) {
                Q.push(curr->right);
            }
        }
    }
}

int height(Node* root) { //O(n)
    if(root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;
    return currHt;
}

int count(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes); //1
    cout << root->data << endl;

    preorder(root); //1 2 4 5 3 6
    cout << endl;

    inorder(root); //4 2 5 1 3 6
    cout << endl;

    postorder(root); //4 5 2 6 3 1
    cout << endl;

    levelOrder(root); //1 2 3 4 5 6

    cout << "height = " << height(root) << endl; //3

    cout << "count of nodes = " << count(root) << endl; //6

    cout << "sum of nodes = " << sum(root) << endl;
    return 0;
}