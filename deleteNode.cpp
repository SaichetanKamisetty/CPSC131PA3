class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->right == NULL && root->left == NULL) {
                root = NULL;
            } else if (root->left == NULL) {
                TreeNode* temp = root->right;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                return temp;
            } else {
                TreeNode* temp = findLowest(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

    TreeNode* findLowest(TreeNode* root) {
        while(root != NULL && root->left != NULL) {
            root = root->left;
        }

        return root;
    }

};
