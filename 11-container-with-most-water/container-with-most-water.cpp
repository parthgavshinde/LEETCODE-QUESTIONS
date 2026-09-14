class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 ;
        int j = height.size()-1;
        int maxi = 0 ;

        while(i<j)
        {
            int length = j - i ;
            int breath = min(height[i],height[j]);

            int area = length*breath ;
            maxi = max(maxi,area);

            if(height[i]>height[j]) j--;
            else i++;
        }
        return maxi;
    }
};