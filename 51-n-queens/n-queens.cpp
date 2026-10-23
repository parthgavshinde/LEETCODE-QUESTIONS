class Solution {
public:
    vector<vector<string>> ans;
    int N;

    bool isValid(vector<string>& board, int row, int col) {
        for(int i = row-1; i>=0; i--)
        {
            if(board[i][col]=='Q') return false;
        }     
        for(int i = row-1 , j = col-1 ; i>=0 && j>=0; i-- ,j--)    {
            if(board[i][j]=='Q') return false;
        }  

        for(int i = row-1 ,j = col+1 ; i>=0&& j<N; i--,j++)
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(vector<string>& board, int row) {
        if (row >= N) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < N; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                helper( board, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));
        helper(board, 0);
        return ans;
    }
};