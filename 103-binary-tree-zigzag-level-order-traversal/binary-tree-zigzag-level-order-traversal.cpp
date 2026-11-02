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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_back(root);
        int j = 1;
        while (!q.empty()) {

            int n = q.size();
            vector<int> curr(n);
            for (int i = 0; i < n; i++) {

                auto temp = q.front();
                q.pop_front();
                if(j%2!=0)
                {
                    curr[i]=temp->val;
                }
                else
                {
                    curr[n-i-1] = temp->val;
                }
                if(temp->left!=NULL)q.push_back(temp->left);
                if(temp->right!=NULL)q.push_back(temp->right);

            }
            j++;
            ans.push_back(curr);
        }
        return ans;
    }
};