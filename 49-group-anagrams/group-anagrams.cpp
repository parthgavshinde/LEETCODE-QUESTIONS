class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp;


        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            string a = nums[i];
            sort(a.begin(),a.end());
            if (mp.find(a) != mp.end()) {
                ans[mp[a]].push_back(nums[i]);
            } else {
                mp[a] = j;
                j++;
                ans.push_back({nums[i]});
            }
        }

        return ans;
    }
};