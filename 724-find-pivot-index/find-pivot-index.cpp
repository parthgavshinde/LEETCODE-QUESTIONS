class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        // Compare left sum (prefix[i]) with right sum (suffix[i + 1])
        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i + 1])
                return i;
        }

        return -1;
    }
};
