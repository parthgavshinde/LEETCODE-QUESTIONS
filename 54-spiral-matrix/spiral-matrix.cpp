class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while(top <= bottom && left <= right)
        {
            
        for (int j = left; j <= right; j++) {
            ans.push_back(matrix[top][j]);
        }
            
        top++;
        
        for(int i = top ; i<=bottom; i++ )
        {
            ans.push_back(matrix[i][right]);
        }
        
        right--;
        if(top<=bottom)
        {
        for(int k = right ; k>=left; k--)
        {
            ans.push_back(matrix[bottom][k]);
        }
        }
        bottom--;
        if(left<=right)
        {
        for(int l = bottom; l>=top; l--)
        {
            ans.push_back(matrix[l][left]);
        }
        } 
        left++;
        }
        return ans;
    }
};