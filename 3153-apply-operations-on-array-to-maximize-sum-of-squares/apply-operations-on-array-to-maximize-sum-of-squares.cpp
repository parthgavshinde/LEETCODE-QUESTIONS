class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> count(32, 0);
        
        for (int num : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((num >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long current_val = 0;
            for (int j = 0; j < 31; ++j) {
                if (count[j] > 0) {
                    current_val |= (1LL << j);
                    count[j]--;
                }
            }
            ans = (ans + (current_val * current_val) % MOD) % MOD;
        }
        
        return ans;
    }
};
