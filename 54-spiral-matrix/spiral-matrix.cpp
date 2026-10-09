class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top row
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // Traverse downwards along the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from right to left across the bottom row (if rows remain)
            if (top <= bottom) {
                for (int k = right; k >= left; k--) {
                    ans.push_back(matrix[bottom][k]);
                }
                bottom--;
            }

            // Traverse upwards along the left column (if columns remain)
            if (left <= right) {
                for (int l = bottom; l >= top; l--) {
                    ans.push_back(matrix[l][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
