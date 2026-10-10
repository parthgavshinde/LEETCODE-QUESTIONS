class Solution {
public:
    int helper(vector<int>& nums, int i, int j, int target) {
        if (i > j) return -1;
        
        int mid = i + (j - i) / 2;
        
        if (nums[mid] == target) return mid;
        // Added 'return' before both recursive calls
        else if (nums[mid] > target) return helper(nums, i, mid - 1, target);
        else return helper(nums, mid + 1, j, target);
    }
    
    int search(vector<int>& nums, int target) {
        // Simple base case for empty array
        if (nums.empty()) return -1; 
        
        return helper(nums, 0, nums.size() - 1, target);
    }
};
