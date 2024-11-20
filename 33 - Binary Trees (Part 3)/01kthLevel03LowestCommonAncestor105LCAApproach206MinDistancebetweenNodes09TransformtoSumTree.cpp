#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

int diam1(Node* root) { //O(n^2) number of nodes in the longest path between 2 leaves
    if(root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam)); //max function can only be operated between two number
}

pair<int, int> diam2(Node* root) { //O(n)
    if(root == NULL) {
        return make_pair(0, 0);
    }
    //(diameter, height)
    pair<int, int> leftInfo = diam2(root->left); //(LD, LH)
    pair<int, int> rightInfo = diam2(root->right); //(RD, RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) { //the whole structure of the subtrees shoulb match
        return false; 
    }

    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot) {
    if(root == NULL && subRoot == NULL) {
        return true;
    } else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot->data) {
        if(isIdentical(root, subRoot)) { //if not then don't return false cause the matching subtree could come later. We need to check that.
            return true;
        }
    }

    int isLeftSubtree = isSubtree(root->left, subRoot);
    if(!isLeftSubtree) {
        return isSubtree(root->right, subRoot);
    }

    return true;
}

void topView(Node* root) {
    queue<pair<Node*, int>> Q; //(node, HD)
    map<int, int> m; //(HD, node->data)

    Q.push(make_pair(root, 0));
    while(!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;
        
        if(m.count(currHD) == 0) {
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL) {
            pair<Node*, int> left = make_pair(currNode->left, currHD-1); //can't do currHD--
            Q.push(left);
        }

        if(currNode->right != NULL) {
            pair<Node*, int > right = make_pair(currNode->right, currHD+1); //can't do currHD++
            Q.push(right);
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }
}

void kthHelper(Node* root, int k, int currLevel) {
    if(root == NULL) {
        return;
    }

    if(currLevel == k) {
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, k, currLevel+1);
    kthHelper(root->right, k, currLevel+1);
}

void kthLevel(Node* root, int k) { //can be done with levelorder too.
    kthHelper(root, k, 1); //in interview it could be given that we only can use 2 parameters
    cout << endl;

}

bool rootToNodePath(Node* root, int n, vector<int> &path) { //O(n) and path has to be passed by reference
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);
    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight) {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA1(Node* root, int n1, int n2) { //O(n); O(n )
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);
    
    int lca = -1;   
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

Node* LCA2(Node* root, int n1, int n2) { //O(n); O(1)
    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA; //if both are NULL rightLCA will be returned and that is NULL which we had to return. So this covers all three other possibility.
}

int dist(Node* root, int n) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == n) { //not return 1 cause if 1 then the distance would get main distance + 1
        return 0;
    }

    int leftDist = dist(root->left, n);
    if(leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);
    if(rightDist != -1) {
        return rightDist + 1;
    }

    return -1;
}

int minDist(Node* root, int n1, int n2) { //O(n)
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int kthAncestor(Node* root, int node, int k) {
    if(root == NULL) {
        return -1;
    }

    if(root->data == node) {
        return 0;
    }

    int leftDist = kthAncestor(root->left, node, k);
    int rightDist = kthAncestor(root->right, node, k);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validVal = leftDist == -1 ? rightDist : leftDist;

    if(validVal + 1 == k) {
        cout << "Kth Ancestor : " << root->data << endl;
    }

    return validVal + 1; // returning the value of k not the ancestor.
}

int transform(Node* root) { //O(n)
    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;

    if(root->left != NULL) {
        root->data += root->left->data;
    }

    if(root->right != NULL) {
        root->data += root->right->data;
    } 

    return currOld;
}

int main() { 
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    kthLevel(root, 3);

    cout << "lca1 = " << LCA1(root, 4, 5) << endl;
    cout << "lca2 = " << LCA2(root, 4, 5)->data << endl;

    cout << "min dist = " << minDist(root, 4, 6) << endl;

    kthAncestor(root, 6, 1);

    transform(root);
    levelOrder(root);
    return 0;
}