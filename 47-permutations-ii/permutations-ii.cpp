class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>>& ans, int idx,
                set<vector<int>>& st) {
        if (idx == nums.size()) {
            if (st.find(nums) == st.end()) {
                st.insert(nums);
                ans.push_back(nums);
            }

            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            helper(nums, ans, idx + 1,st);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        helper(nums, ans, 0, st);
        return ans;
    }
};