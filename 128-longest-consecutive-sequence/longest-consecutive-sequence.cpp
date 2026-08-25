class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;

        for (int x : s) {
            // Only start counting if 'x' is the beginning of a sequence
            if (s.find(x - 1) == s.end()) {
                int current_num = x;
                int count = 1;

                while (s.find(current_num + 1) != s.end()) {
                    current_num += 1;
                    count++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};
