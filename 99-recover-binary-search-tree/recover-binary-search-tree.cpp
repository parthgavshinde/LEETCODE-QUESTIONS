class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        // If the current node's value is less than the previous node's value, it's a violation
        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        // Update prev to the current node before going right
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Find the swapped nodes
        inorder(root);

        // Swap their values back
        if (first != nullptr && last != nullptr) {
            swap(first->val, last->val);
        } else if (first != nullptr && middle != nullptr) {
            swap(first->val, middle->val);
        }
    }
};
