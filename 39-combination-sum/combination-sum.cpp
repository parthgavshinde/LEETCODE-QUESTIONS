 class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& current, int sum, int index) {
        // Base case: target reached
        if (sum == target) {
            ans.push_back(current);
            return;
        }
        // Base case: sum exceeded or array exhausted
        if (sum > target || index >= candidates.size()) {
            return;
        }
        
        // Option 1: Pick the current candidate (keep index the same to allow reuse)
        current.push_back(candidates[index]);
        helper(candidates, target, ans, current, sum + candidates[index], index);
        
        // Option 2: Backtrack and skip the current candidate (increment index)
        current.pop_back();
        helper(candidates, target, ans, current, sum, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        helper(candidates, target, ans, current, 0, 0);
        return ans;
    }
};
