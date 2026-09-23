#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        if (nums.empty()) return {};

        // 1. Sort intervals based on starting points
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        ans.push_back(nums[0]);

        // 2. Iterate and merge overlapping intervals
        for (int i = 1; i < nums.size(); ++i) {
            // Check if current interval overlaps with the last interval in ans
            if (nums[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            } else {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
