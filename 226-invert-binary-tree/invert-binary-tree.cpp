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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
            
        deque<TreeNode*> q;
        q.push_back(root);
        
        while (!q.empty()) {
            // 1. Get the current node
            TreeNode* curr = q.front();
            q.pop_front();
            
            // 2. Swap its left and right children
            swap(curr->left, curr->right);
            
            // 3. Add the children to the queue to process them next
            if (curr->left != nullptr)
                q.push_back(curr->left);
            if (curr->right != nullptr)
                q.push_back(curr->right);
        }
        
        return root;
    }
};
