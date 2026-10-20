class Solution {
public:
    void helper(vector<int>& candidates, int target,
                vector<vector<int>>& ans,
                vector<int>& curr, int start) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            helper(candidates, target - candidates[i],
                   ans, curr, i + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, ans, curr, 0);
        return ans;
    }
};