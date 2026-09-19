class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0;
        int right = 0;
        vector<int>ans;
        while(left<m&& right<nums2.size())
        {
            if(nums1[left]<nums2[right])
            {
                ans.push_back(nums1[left]);
                left++;
            }
            else
            {
                ans.push_back(nums2[right]);
                right++;
            }
        }
        while(left<m){
            ans.push_back(nums1[left]);
            left++;
        }
        while(right<nums2.size())
        {
            ans.push_back(nums2[right]);
            right++;
        }

        for(int i = 0 ; i<ans.size(); i++)
        {
            nums1[i] = ans[i];
        }
    }
};