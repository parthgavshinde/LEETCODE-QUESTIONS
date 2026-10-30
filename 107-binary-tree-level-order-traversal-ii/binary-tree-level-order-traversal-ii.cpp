class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> level; // Store current level directly
            
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
            // Add the level to our result
            result.push_back(level);
        }
        
        // Reverse the top-down result to make it bottom-up
        reverse(result.begin(), result.end());
        
        return result;
    }
};
