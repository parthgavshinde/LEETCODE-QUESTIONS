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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {} ;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        q.push(root);

        while (!q.empty()) {
            vector<int> curr ;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                
                TreeNode* temp = q.front();
                curr.push_back(temp->val);

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                q.pop();
            }
            ans.push_back(curr);

        }
        return ans;
    }
};