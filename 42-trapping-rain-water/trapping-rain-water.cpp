class Solution {
public:
    int trap(vector<int>& nums) {
        int ans = 0;
        int l = 0; 
        int r = nums.size() - 1;
        int lmax = 0; 
        int rmax = 0;

        while (l < r) {
            lmax = max(lmax, nums[l]);
            rmax = max(rmax, nums[r]);

            if (lmax < rmax) {
                ans += lmax - nums[l];
                l++; // Move only the left pointer
            } else {
                ans += rmax - nums[r];
                r--; // Move only the right pointer
            }
        }

        return ans;
    }
};
