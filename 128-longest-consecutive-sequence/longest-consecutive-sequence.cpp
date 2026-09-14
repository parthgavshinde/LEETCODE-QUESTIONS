class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = 0;

        for (int num : st) {
            // Only start counting if 'num' is the beginning of a sequence
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentStreak++;
                }

                maxi = max(maxi, currentStreak);
            }
        }

        return maxi;
    }
};
