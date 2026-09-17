#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // If required total flowers exceed array size, it's impossible
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count bouquets that can be made on day 'mid'
            int bouquets = 0;
            int contiguous = 0;

            for (int day : bloomDay) {
                if (day <= mid) {
                    contiguous++;
                    if (contiguous == k) {
                        bouquets++;
                        contiguous = 0; // Reset after forming one bouquet
                    }
                } else {
                    contiguous = 0; // Reset if the chain of bloomed flowers breaks
                }
            }

            if (bouquets >= m) {
                ans = mid;     // Try to find a smaller valid day
                high = mid - 1;
            } else {
                low = mid + 1; // Need more days to bloom enough flowers
            }
        }

        return ans;
    }
};
