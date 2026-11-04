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
private:
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        // 1. Flatten the right subtree first
        flatten(root->right);

        // 2. Flatten the left subtree
        flatten(root->left);

        // 3. Process current node: point right to prev, nullify left
        root->right = prev;
        root->left = nullptr;

        // 4. Update prev to the current node
        prev = root;
    }
};
