class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long sum = 0 ; 

        for(int i = 0 ; i<=nums.size(); i++)
        {
            sum += i; 
        }

        int miss = 0 ; 
        for(int i : nums)
        {
            miss += i;
        }

        return  sum-miss;
    }
};