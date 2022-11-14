class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: return NULL if val is not found.
        if (root == NULL) {
            return NULL;
        // Recursive Cases:
        // If val of current node is greater than val, traverse left in the tree.
        } else if (root->val > val) {
            return searchBST(root->left, val);
        // If val of current node is less than val, traverse right in the tree.
        } else if (root->val < val) {
            return searchBST(root->right, val);
        // Otherwise, value is found and return the current node it is on.
        } else {
            return root;
        }
    }
};
