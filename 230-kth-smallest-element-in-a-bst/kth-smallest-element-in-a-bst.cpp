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
    void helper(TreeNode* root, set<int>& ans) {
        if (root == nullptr)
            return;

        ans.insert(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        set<int> ans;
        helper(root, ans);

        auto it = std::next(ans.begin(), k-1);

        return *it;


    }
};