class Solution {
public:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        // Base case: string length is 2*n, meaning we've placed all parentheses
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }
        
        // If we can still add an open parenthesis, add it and recurse
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back(); // backtrack
        }
        
        // If we have more open parentheses than closed ones, we can add a closed parenthesis
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
