class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        vector<int> pse(nums.size(), -1);
        vector<int> nse(nums.size(), nums.size());
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = 0; i<nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        int maxArea = 0 ;
        for(int i = 0 ; i<nums.size(); i++)
        {
            int width = nse[i]-pse[i]-1;
            maxArea = max(maxArea , nums[i]*width);
        }
        return maxArea;
    }
};