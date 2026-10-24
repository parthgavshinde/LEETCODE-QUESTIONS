class Solution {
public:
    vector<vector<string>> ans;

    void helper(string& s, int idx, vector<string>& temp) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {

            if (isValid(s,  idx,i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                helper(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }
    bool isValid(string si, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            if (si[i] != si[j]) {
                return false;
            }

            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(s, 0, temp);
        return ans;
    }
};