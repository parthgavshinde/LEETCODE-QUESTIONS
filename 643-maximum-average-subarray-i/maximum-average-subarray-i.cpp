class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN ; 
        double avg  = 0 ; 
        int p = 1; 
        int j = 0 ;
        for(int i = 0 ; i<nums.size(); i++)
        {
            avg += nums[i];
            if(p>=k)
            {
                double a = avg/k; 
                ans = max(ans,a);
                avg = avg - nums[j] ;
                j++;
            }
            p++;
        }
        return ans ; 
    }
};