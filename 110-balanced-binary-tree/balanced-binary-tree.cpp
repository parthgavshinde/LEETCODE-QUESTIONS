class Solution {
public:
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = helper(root->left);
        if (left == -1) return -1; // Early exit if left subtree is unbalanced

        int right = helper(root->right);
        if (right == -1) return -1; // Early exit if right subtree is unbalanced

        if (abs(left - right) > 1) return -1; // Current node is unbalanced

        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
