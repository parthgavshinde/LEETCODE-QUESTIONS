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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int min_depth = 1 ;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();

                if (temp->left == nullptr && temp->right == nullptr) {
                    return min_depth;
                }
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
            min_depth += 1;
        }
        return min_depth ; 
    }
};