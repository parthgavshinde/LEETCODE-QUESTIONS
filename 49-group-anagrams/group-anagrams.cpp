class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& s : strs) {
            // 26 lowercase English letters ke liye frequency array
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // Frequency array se unique key string banana
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]); // Hash `#` separator ke liye
            }
            
            mp[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};
