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
    int sum = 0;
    void helper(TreeNode* root, string si) {
        if (root == nullptr)
            return;
        si+=(to_string(root->val));
        if(root->left==nullptr && root->right==nullptr)
        {
            sum += stoi(si);
            si.pop_back();
            return ;
        }

        
        helper(root->left, si);
      
        helper(root->right,si);
          si.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string si = "";
        helper(root, si);
        return sum;
    }
};