/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<vector<int>> ans ;
    void helper(TreeNode* root , int sum , int target,vector<int> temp){
        if(root==nullptr) return ;
        sum += root->val;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            if(sum==target)
            {
                ans.push_back(temp);
            }
            return ;
        }
        helper(root->left,sum,target,temp);
        helper(root->right,sum,target,temp);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0 ;
        vector<int> temp ;
        helper(root,sum,targetSum,temp);
        return ans;
    }
};