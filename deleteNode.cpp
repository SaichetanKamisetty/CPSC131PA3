class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Node that needs to be deleted not found, retrun root.
        if (root == NULL) {
            return root;
        // Recursive cases:
        // If node val is greater than key, traverse left.
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
         // If node val is less than key, traverse right.
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
         // Otherwise, node that needs to be deleted is found.
        } else {
            // 3 Cases:
            // If leaf, just set the current root to null.
            if (root->right == NULL && root->left == NULL) {
                root = NULL;
            // If only 1 child & it is on the right, delete current node by setting it equal to child node to connect it to the tree.
            } else if (root->left == NULL) {
                root = root->right;
            // If only 1 child & it is on the left, delete current node by setting it equal to child node to connect it to the tree.
            } else if (root->right == NULL) {
                root = root->left;
            // If there are two children on the node.
            } else {
                // Set a temp treenode to the lowest node in the right subtree of the node.
                TreeNode* temp = findLowest(root->right);
                // Swaps the current root value to the lowest node value in the right subtree to keep order of the BST.
                root->val = temp->val;
                // Once swapped, there is still the lowest node value, so call the function again to delete the node.
                root->right = deleteNode(root->right, temp->val);
            }
        }
        // Return the root after all changes were made.
        return root;
    }
    
    // Helper function, this goes through the left values of the tree to find the lowest value of the root that was passed through.
    TreeNode* findLowest(TreeNode* root) {
        while(root != NULL && root->left != NULL) {
            root = root->left;
        }

        return root;
    }

};
