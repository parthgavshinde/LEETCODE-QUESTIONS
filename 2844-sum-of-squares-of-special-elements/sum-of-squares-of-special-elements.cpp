class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                // Add the square for factor 'i'
                sum += nums[i - 1] * nums[i - 1];
                
                // Add the square for the paired factor 'n / i'
                // Ensure we don't double-count if i * i == n
                if (i * i != n) {
                    int pair_idx = n / i;
                    sum += nums[pair_idx - 1] * nums[pair_idx - 1];
                }
            }
        }
        return sum;
    }
};
