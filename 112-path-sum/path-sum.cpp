/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int sum, int target) {

        if (root == nullptr)
            return false;

        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target)
                return true;
            else
                return false;
        }

        bool left = helper(root->left, sum, target);
        bool right = helper(root->right, sum, target);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, sum, targetSum);
    }
};