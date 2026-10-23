class Solution {
public:
    void helper( vector<int>& nums, vector<vector<int>>& result,
    vector<int> &temp , unordered_set<int> &st) {
        // Base case: if we have considered all elements, add the permutation to the result
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i])==st.end())
            {
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                helper(nums,result,temp,st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp ;
        unordered_set<int> st;
        helper(nums, result,temp,st);
        return result;
    }
};
