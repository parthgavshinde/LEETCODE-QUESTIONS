class Solution {
public:
    // Store TreeNode pointers instead of just their integer values
    void helper(TreeNode* root, vector<TreeNode*>& inorder) {
        if (root == nullptr) {
            return;
        }

        helper(root->left, inorder);
        inorder.push_back(root); // Store the actual node
        helper(root->right, inorder);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        helper(root, inorder);
        
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;

        for (int i = 1; i < inorder.size(); i++) {
            // Find the nodes where the BST property is violated
            if (inorder[i]->val < inorder[i - 1]->val) {
                if (first == nullptr) {
                    // First violation found
                    first = inorder[i - 1];
                    middle = inorder[i];
                } else {
                    // Second violation found
                    last = inorder[i];
                }
            }
        }

        // Swap the values of the two incorrectly placed nodes
        if (first != nullptr && last != nullptr) {
            swap(first->val, last->val);
        } else if (first != nullptr && middle != nullptr) {
            swap(first->val, middle->val);
        }
    }
};
