#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int> &nums, int start, int end, int node) { //O(n);
        if(start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end-start)/2;

        buildTree(nums, start, mid, 2*node+1);
        buildTree(nums, mid+1, end, 2*node+2);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    int maxQuery(int qi, int qj, int si, int sj, int node) { //O(logn)          No base case is required here
        if(qi > sj || qj < si) { //no overlap
            return INT_MIN; //cause it doesn't effect the result
        }

        if(qi <= si && sj <= qj) { //complete
            return tree[node]; //no need to call for it's subtrees cause this is the max of all the subtrees
        }

        //partial
        int mid = si + (sj-si)/2;

        int leftMax = maxQuery(qi, qj, si, mid, 2*node+1);
        int rightMax = maxQuery(qi, qj, mid+1, sj, 2*node+2);

        return max(leftMax, rightMax);
    }

    void updateUtil(int idx, int newVal, int start, int end, int node) { //O(logn)
        if(start == end) {
            tree[node] = newVal;
            return;
        }

        int mid = start + (end-start)/2;

        if(start <= idx && idx <= mid) { //left
            updateUtil(idx, newVal, start, mid, 2*node+1);
        } else { //right
            updateUtil(idx, newVal, mid+1, end, 2*node+2);
        }

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

public:
    SegmentTree(vector<int> &nums) {
        n = nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, n-1, 0);
    }

    void printTree() {
        for(int el : tree) {
            cout << el << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return maxQuery(qi, qj, 0, n-1, 0);
    }

    void updateQuery(int idx, int newVal) {
        updateUtil(idx, newVal, 0, n-1, 0);
    }
};

int main() {
    //Range Max Queries
    vector<int> nums = {6, 8, -1, 2, 17, 1, 3, 2, 4};

    SegmentTree st(nums);
    st.printTree();

    cout << st.rangeQuery(2, 5) << endl;
    cout << st.rangeQuery(5, 8) << endl;

    st.updateQuery(4, 5);
    cout << st.rangeQuery(0, 8) << endl;
    return 0;
}