class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // If we find the first character, start the DFS
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        // Base case: all characters found
        if (idx == word.length()) return true;
        
        // Check boundaries and if the current character matches
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }
        
        // Mark the current cell as visited by temporarily altering it
        char temp = board[i][j];
        board[i][j] = '*'; 
        
        // Explore all 4 adjacent directions
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);
                     
        // Backtrack: restore the cell's original character
        board[i][j] = temp; 
        
        return found;
    }
};
