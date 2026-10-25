class Solution {
public:

    bool isValid(string temp)
    {
        stack<int> st;

        for(int i = 0 ; i<temp.size(); i++)
        {
            if(temp[i]=='(')
            {
                st.push(temp[i]);
            }
            else if(temp[i]==')')
            {
                if(st.empty())
                {
                    return false ;
                }
                st.pop();
            }
        }
        return st.empty() ;
    }
    void helper(vector<string>& ans, int& n, string& temp, int count) {
        if (temp.size() == n * 2) {
            if (isValid(temp)) {
                ans.push_back(temp);
               
            }
             return;
        }

        temp.push_back('(');

        helper(ans, n, temp, count);

        temp.pop_back();
        temp.push_back(')');
        helper(ans, n, temp, count);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string t = "";
        int count = 0;
        helper(ans, n, t, count);

        return ans;
    }
};