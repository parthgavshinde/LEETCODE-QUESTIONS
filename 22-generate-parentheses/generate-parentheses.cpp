class Solution {
public:
    void helper(vector<string>& ans, int n, string& temp, int open, int close) {
        // Base case: string is complete
        if (temp.size() == n * 2) {
            ans.push_back(temp);
            return;
        }

        // We can add an opening bracket if we haven't used all 'n' of them
        if (open < n) {
            temp.push_back('(');
            helper(ans, n, temp, open + 1, close);
            temp.pop_back(); // backtrack
        }

        // We can add a closing bracket only if we have more open than close brackets
        if (close < open) {
            temp.push_back(')');
            helper(ans, n, temp, open, close + 1);
            temp.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        helper(ans, n, temp, 0, 0); // Track open and close bracket counts
        return ans;
    }
};
