class Solution {
public:

void helper(vector<int> & nums, vector<int> & a , vector<vector<int>> &ans, int i ){

    if(i==nums.size())
    {
        ans.push_back(a);
        return ;
    }
    a.push_back(nums[i]);
    helper(nums,a,ans,i+1);
    a.pop_back();
    helper(nums,a,ans,i+1);
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ; 
        vector<int> a ;
        helper(nums,a,ans,0);
        sort(ans.begin(),ans.end());
        return ans ;
    }
};