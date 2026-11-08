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
    int a = 0 ; 
    void helper(TreeNode* root,int k ,int &counter) {
        if (root == nullptr)
            return;


        helper(root->left, k,counter);
        counter += 1 ;
        if(counter == k)
        {
            a = root->val ; 
            return ;
        }
        helper(root->right,k,counter);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0 ; 
        helper(root,k,counter);
        return a ; 
    }
};