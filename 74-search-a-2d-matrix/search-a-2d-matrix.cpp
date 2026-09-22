class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        
        
        int r = 0 ; 
        int c = 0 ; 
        int r_end = matrix.size()-1;
        int c_end= matrix[0].size()-1;

        while(r<=r_end && c<=c_end)
        {
            int mid_r = r+ (r_end-r)/2;
            int mid_c = c+(c_end-c)/2;

            if(matrix[mid_r][mid_c]==target)
            {
                return true;
            }
            else if(target<=matrix[mid_r].back() && target>=matrix[mid_r].front() )
            {
                if(matrix[mid_r][mid_c]<target)
                {
                    c = mid_c+1;
                }
                else
                {
                    c_end = mid_c-1;
                }
            }
            else if(target<matrix[mid_r].back())
            {
                r_end = mid_r-1;
            }
            else
            {
                r = mid_r+1;
            }

        }
        
        return false;
    }
};