class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi = INT_MIN ;
        int first = 0;
        double sum = 0 ; 
        for(int i = 0 ; i<nums.size(); i++)
        {
            sum = sum +nums[i];
            if(i>=k-1)
            {
                double avg  = sum/k;
                maxi = max(maxi,avg);
                sum = sum - nums[first];
                first = first+  1;
            }
        }
        return maxi;
    }
};