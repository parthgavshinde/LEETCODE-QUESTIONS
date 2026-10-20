class Solution {
public:
    void helper(vector<int>& nums, int target, vector<vector<int>>& ans,
                int sum,vector<int> &dummy,int i) {
        if (sum==target){
             ans.push_back(dummy);
             return;
             }
        if(sum>target||i>=nums.size())
        {
            return ; 
        }
       
        dummy.push_back(nums[i]);
        helper(nums,target,ans,sum+nums[i],dummy,i);
        dummy.pop_back();
        helper(nums,target,ans,sum,dummy,i+1);
        
      

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int sum = 0 ;
        vector<int> dummy;
        helper(candidates,target,ans,sum,dummy,0);
        return ans;
    }
};