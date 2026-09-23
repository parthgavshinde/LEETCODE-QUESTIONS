class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        ans.push_back({nums[0]});

        int i = 1 ; 
        int j = 0 ; 

        int k = 0 ; 
        int l = 1 ;
        while(i<nums.size())
        {
            if(nums[i][j]>ans[k][l])
            {
                ans.push_back({nums[i]});
                k++;
            }
            else if(nums[i][j+1]>ans[k][l])
            {
                ans[k][l] = nums[i][j+1];      
            }
            i++;
        }
        return ans;
    }

};