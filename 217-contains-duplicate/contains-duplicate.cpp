class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            // Agar number pehle se set me hai
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            // Number ko set me daal do
            s.insert(nums[i]);
        }

        return false;
    }
};
