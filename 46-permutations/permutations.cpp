class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<vector<int>>& result) {
        // Base case: if we have considered all elements, add the permutation to the result
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            helper(idx + 1, nums, result); // Recurse for the next index
            swap(nums[i], nums[idx]);      // Backtrack
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(0, nums, result);
        return result;
    }
};
