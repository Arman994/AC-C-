class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(min(p->val, q->val) > root->val) {
                root = root->right;
            } else if(max(p->val, q->val) < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }

        return root; // root = NULL;
    }
};