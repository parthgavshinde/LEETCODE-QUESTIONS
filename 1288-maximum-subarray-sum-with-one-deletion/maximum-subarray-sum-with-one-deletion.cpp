class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int max_no_del = arr[0]; // Maximum sum ending at i WITHOUT deletion
        int max_one_del = arr[0]; // Maximum sum ending at i WITH at most one deletion
        int overall_max = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            // Either delete current element (keep max_no_del) OR keep current element after a previous deletion
            max_one_del = max(max_no_del, max_one_del + arr[i]);
            
            // Standard Kadane's algorithm (start new subarray at arr[i] OR extend previous)
            max_no_del = max(arr[i], max_no_del + arr[i]);

            // Update overall maximum across both states
            overall_max = max({overall_max, max_no_del, max_one_del});
        }

        return overall_max;
    }
};
