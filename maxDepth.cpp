class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return 1 + max(maxDepth(root->right), maxDepth(root->left));
        }
    }
};
