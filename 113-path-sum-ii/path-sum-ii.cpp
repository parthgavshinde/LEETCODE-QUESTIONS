class Solution {
public:
    vector<vector<int>> ans;

    void helper(TreeNode* root, int sum, int target,
                vector<int>& temp) {

        if (root == nullptr) return;

        sum += root->val;
        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == target)
                ans.push_back(temp);

            temp.pop_back();
            return;
        }

        helper(root->left, sum, target, temp);
        helper(root->right, sum, target, temp);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();

        vector<int> temp;
        helper(root, 0, targetSum, temp);

        return ans;
    }
};