class Solution {
public:
    void helper(vector<int>& nums, vector<int>& a, vector<vector<int>>& ans, int idx) {
        ans.push_back(a);
        
        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates at the same level of the recursion tree
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            a.push_back(nums[i]);
            helper(nums, a, ans, i + 1);
            a.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        
        // Sort the array to easily group and skip duplicates
        sort(nums.begin(), nums.end());
        
        helper(nums, a, ans, 0);
        return ans;
    }
};
