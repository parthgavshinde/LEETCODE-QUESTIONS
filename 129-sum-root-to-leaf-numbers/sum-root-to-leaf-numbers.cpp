class Solution {
public:
    int helper(TreeNode* root, int currentSum) {
        if (root == nullptr) return 0;
        
        currentSum = currentSum * 10 + root->val;
        
        // If it's a leaf node, return the accumulated number
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum;
        }
        
        // Return the sum of both subtrees
        return helper(root->left, currentSum) + helper(root->right, currentSum);
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};
