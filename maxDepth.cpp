class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case, returns 0 after reaching end of the BST.
        if (root == NULL) {
            return 0;
        } else {
         // Recursive case, uses recursive DST to find the maxDepth of each subtree and then compares them and returns it.
         // the + 1 is added for the root, since it isn't included when originally doing the recursion.
            return max(maxDepth(root->right) + 1, maxDepth(root->left) + 1);
        }
    }
};
