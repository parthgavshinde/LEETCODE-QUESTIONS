class Solution {
public:
    bool helper(string& s, string& t, int i, int j) {
        // Base case: if we have matched all characters in s, it's a subsequence
        if (i == s.size()) return true;
        
        // Base case: if we reach the end of t but not s, it's not a subsequence
        if (j == t.size()) return false;
        
        // If characters match, move both pointers to check the next character in s
        if (s[i] == t[j]) {
            return helper(s, t, i + 1, j + 1);
        }
        
        // If they don't match, just move the t pointer forward
        return helper(s, t, i, j + 1);
    }

    bool isSubsequence(string s, string t) {
        return helper(s, t, 0, 0);
    }
};
