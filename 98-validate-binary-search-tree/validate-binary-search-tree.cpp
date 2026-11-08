class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }

    bool check(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;

        // The node must be within the valid range
        if (node->val <= minVal || node->val >= maxVal)
            return false;

        // Check left and right subtrees
        bool leftOK = check(node->left, minVal, node->val);
        bool rightOK = check(node->right, node->val, maxVal);

        return leftOK && rightOK;
    }
};