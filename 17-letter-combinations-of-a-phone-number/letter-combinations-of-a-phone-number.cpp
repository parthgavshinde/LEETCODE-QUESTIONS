class Solution {
public:
    void helper(string digits, unordered_map<char, string>& mp, string &temp,vector<string> &ans,int idx) {
        if (idx >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i =0 ; i<str.length(); i++)
        {
            temp.push_back(str[i]);
            helper(digits,mp,temp,ans,idx+1);
            temp.pop_back();
        } 
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> ans ;
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        helper(digits,mp,temp,ans,0);
        return ans ;
    }
};