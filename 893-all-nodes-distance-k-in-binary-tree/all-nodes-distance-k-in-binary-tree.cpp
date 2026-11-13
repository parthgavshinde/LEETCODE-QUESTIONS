/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;

        if (root->left != NULL)
            mp[root->left] = root;
        solve(root->left, mp);
        if (root->right != NULL)
            mp[root->right] = root;
        solve(root->right, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr)
            return {};


        unordered_map<TreeNode*, TreeNode*> mp;

        solve(root, mp);

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> st;
        st.insert(target);

        while (!q.empty() && k > 0) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                if (temp->left != nullptr && st.find(temp->left) == st.end()) {

                    q.push(temp->left);
                    st.insert(temp->left);
                }
                if (temp->right != nullptr &&
                    st.find(temp->right) == st.end()) {

                    q.push(temp->right);
                    st.insert(temp->right);
                }
                if (mp[temp] != nullptr && st.find(mp[temp]) == st.end()) {


                    q.push(mp[temp]);
                    st.insert(mp[temp]);
                }
            }
            k--;
        }
        vector<int> ans;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};