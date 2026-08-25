class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0 ;

        int left = 0 ; 
        int right = height.size()-1;

        while(left<right)
        {
            int area = (right-left)*min(height[left],height[right]);

            maxi = max(maxi,area);

            if(height[left]>height[right]) right--;
            else left++;
        }
        return maxi;
    }
};