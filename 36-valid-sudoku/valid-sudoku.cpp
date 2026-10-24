class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; i++) {
            string a = "";
            string b = "";
            string c = "";
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                a = std::to_string(board[i][j]) + "#" +
                    "i =" + std::to_string(i);
                b = std::to_string(board[i][j]) + "#" +
                    "j =" + std::to_string(j);
                c = std::to_string(board[i][j]) + "#" + std::to_string(i/3) +
                    std::to_string(j/3);

                if (st.find(a) != st.end() || st.find(b) != st.end() ||
                    st.find(c) != st.end()) {
                    return false;
                }
                st.insert(a);
                st.insert(b);
                st.insert(c);
            }
        }
        return true;
    }
};