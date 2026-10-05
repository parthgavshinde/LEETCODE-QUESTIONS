class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> ans(26, 0);

        for (int i = 0; i < s.size(); i++) {
            ans[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            ans[t[i] - 'a']--;

            if (ans[t[i] - 'a'] < 0) return false;
        }

        return true;
    }
};