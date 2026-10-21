class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr,
                unordered_map<int, int>& mp) {

        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                curr.push_back(nums[i]);
                mp[nums[i]]++;
                helper(ans, nums, curr, mp);
                curr.pop_back();
                mp.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, int> mp;
        helper(ans, nums, curr, mp);
        return ans;
    }
};