class Solution {
public:
    void helper(vector<int>& nums, int target, int start,
                vector<vector<int>>& ans, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > target)
                break;
            curr.push_back(nums[i]);
            helper(nums, target - nums[i],i + 1, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, ans, curr);

        return ans;
    }
};