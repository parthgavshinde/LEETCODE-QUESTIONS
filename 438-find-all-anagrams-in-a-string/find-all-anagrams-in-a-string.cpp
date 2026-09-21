class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26,0);
        vector<int> answer;
        if(s.length()<p.length()) return answer;
        for(int i=0;i<p.length();i++){
            freq[p[i]-'a']++;
        }
        for(int i=0;i<=s.length() - p.length();i++){
            vector<int> check(26,0);
            for(int j=0;j<p.length();j++){
               check[s[i+j]-'a']++;
            }
            if(check==freq) answer.push_back(i);
        }
        return answer;
    }
};