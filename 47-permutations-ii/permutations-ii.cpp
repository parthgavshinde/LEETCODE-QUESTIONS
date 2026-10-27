class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip if the index is already used
            if (visited[i]) continue;
            
            // Skip duplicates to ensure unique permutations
            // If the current number is the same as the previous, and the previous wasn't used in this depth, skip it.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            
            visited[i] = true;
            temp.push_back(nums[i]);
            
            helper(ans, temp, nums, visited);
            
            // Backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        
        // Sorting is crucial for the duplicate skipping logic to work
        sort(nums.begin(), nums.end());
        
        helper(ans, temp, nums, visited);
        return ans;
    }
};
