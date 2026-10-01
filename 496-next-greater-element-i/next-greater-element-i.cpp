class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Step 1: Find next greater for each element in nums2
        for (int i = 0; i < nums2.size(); i++) {
            int x = nums2[i];
            while (!st.empty() && x > st.top()) {
                nextGreater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // Step 2: For elements with no next greater, store -1
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Step 3: Build result for nums1 using the map
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            int x = nums1[i];
            result.push_back(nextGreater[x]);
        }

        return result;
    }
};