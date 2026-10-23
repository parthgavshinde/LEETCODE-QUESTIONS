class Solution {
public:
    vector<vector<string>> ans;
    int N;
    unordered_set<int> cols;
    unordered_set<int> diagonal;
    unordered_set<int> anti_diagonal;

    void helper(vector<string>& board, int row) {
        if (row >= N) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < N; col++) {
            int digConstant = row + col;
            int antiDigonalConstant = row - col;
            if (cols.find(col) != cols.end() ||
                diagonal.find(digConstant) != diagonal.end() ||
                anti_diagonal.find(antiDigonalConstant) !=
                    anti_diagonal.end()) {
                continue;
            }
            cols.insert(col);
            diagonal.insert(digConstant);
            anti_diagonal.insert(antiDigonalConstant);
            board[row][col] = 'Q';

            helper(board, row + 1);

            cols.erase(col);
            diagonal.erase(digConstant);
            anti_diagonal.erase(antiDigonalConstant);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));

        helper(board, 0);
        return ans;
    }
};