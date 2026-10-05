class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> ans ; 
        for(const string& s : strs)
        {
            vector<int> count(26,0) ;
            for(int i = 0 ; i<s.size(); i++)
            {
                count[s[i]-'a']++;
            }
            string key = "";

            for(int i = 0 ; i<26; i++)
            {
                key += "#" + to_string(count[i]);
            }
            mp[key].push_back(s);
        }
        for(auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};