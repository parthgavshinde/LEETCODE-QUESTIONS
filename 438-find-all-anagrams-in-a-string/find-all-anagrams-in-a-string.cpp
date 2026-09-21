class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0);
        vector<int> answer;
        
        int n = s.length();
        int m = p.length();

        // Edge case handling
        if (n < m) return answer;

        // Count frequencies of p
        for (int i = 0; i < m; i++) {
            freq[p[i] - 'a']++;
        }

        // Check every window of size m
        for (int i = 0; i <= n - m; i++) {
            vector<int> check(26, 0);
            for (int j = 0; j < m; j++) {
                check[s[i + j] - 'a']++; // Fix: s[i + j] badalkar current window ko count karega
            }
            if (check == freq) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};
