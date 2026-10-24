class Solution {
public:
    void  helper(int k,int target,vector<vector<int>>&ans,vector<int> &temp,int idx,int v){
        if(target<0) return ;
        if(v==k)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return ;
        }
        for(int i = idx; i<=9; i++)
        {
            
            temp.push_back(i);
            helper(k,target-i,ans,temp,i+1,v+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> ans;
       vector<int> temp;
       helper(k,n,ans,temp,1,0);
       return ans;
    }
};