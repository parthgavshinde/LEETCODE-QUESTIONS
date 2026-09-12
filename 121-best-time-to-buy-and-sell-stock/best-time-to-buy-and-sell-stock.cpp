class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int buy = nums[0];
        int profit = 0;
        int maxi = 0;

        for(int i = 1; i<nums.size(); i++)
        {
            buy = min(nums[i],buy);
            profit = nums[i] - buy;
            maxi = max(profit,maxi);
        }
        return maxi;
        
    }
};