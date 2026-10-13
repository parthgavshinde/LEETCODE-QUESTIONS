class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9 + 7;
        
        // Precompute powers of 2 modulo 1e9+7 to prevent overflow
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        
        int count = 0;
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            // If the min and max satisfy the condition
            if (nums[left] + nums[right] <= target) {
                // All subsets formed by elements between left and right are valid
                count = (count + power[right - left]) % mod;
                left++;
            } else {
                // If sum is too large, decrease the max element
                right--;
            }
        }
        
        return count;
    }
};
