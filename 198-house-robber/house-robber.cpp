class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_sum = 0 ;
        int new_sum = nums[0] ;
        int a = 0 ; 

        for(int i = 1 ; i<nums.size(); i++)
        {
            int cu = prev_sum+nums[i];
            if(new_sum<cu)
            {
                prev_sum = new_sum ;
                new_sum = cu;
            }
            else
            {
                prev_sum = new_sum ;
                
            }
        }  
        return new_sum ; 
    }
};