class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                long long sum = nums[i] + nums[j] + nums[k];
                int diff = target - sum;
                
                if (abs(diff) < closest) {
                    closest = abs(diff); 
                    ans = sum;
                }
                
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    k--; 
                } else {
                    j++; 
                }
            }
        }
        return ans;
    }
};
