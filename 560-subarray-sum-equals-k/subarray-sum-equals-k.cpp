class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // Base case: prefix sum of 0 appears once before starting
        int sum = 0; 
        int count = 0; 
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // Check if there is a prefix sum that satisfies (sum - prefix_sum = k)
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            
            // Increment the frequency of the current prefix sum
            mp[sum]++;
        }
        
        return count;
    }
};
