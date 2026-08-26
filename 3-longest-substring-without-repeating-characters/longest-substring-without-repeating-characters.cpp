class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ans;
        int maxi = 0;
        int prev = 0;

        for (int i = 0; i < s.size(); i++) {
            // Shrink window until the duplicate s[i] is removed
            while (ans.find(s[i]) != ans.end()) {
                ans.erase(s[prev]);
                prev++;
            }
            
            // Add current character to window
            ans.insert(s[i]);
            maxi = max(maxi, (int)ans.size());
        }

        return maxi;
    }
};
