class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(left<nums.size())
        {
        if(nums[left]>target )
        {
            if(right>=0)
            {
                if(nums[right]<target)
                {
                    return left;
                }
                else return 0;
            }
            else
            {
                return left;
            }
            
        }
        else
        {
            return right;
        }
        }
        else
        {
            return left;
        }

    return 0 ; 
    }
    
}
;