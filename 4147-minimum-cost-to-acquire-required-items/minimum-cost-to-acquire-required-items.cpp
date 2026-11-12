#include <algorithm>

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // Option 1: Buy entirely separately
        long long option1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        
        // Option 2: Buy 'costBoth' until the smaller need is fulfilled, 
        // then buy the rest separately
        int minNeed = std::min(need1, need2);
        long long option2 = 1LL * minNeed * costBoth 
                          + 1LL * (need1 - minNeed) * cost1 
                          + 1LL * (need2 - minNeed) * cost2;
        
        // Option 3: Buy 'costBoth' until the larger need is fulfilled
        // (This covers the case where costBoth is incredibly cheap, cheaper than cost1 or cost2 alone)
        int maxNeed = std::max(need1, need2);
        long long option3 = 1LL * maxNeed * costBoth;
        
        // Return the minimum of all three valid options
        return std::min({option1, option2, option3});
    }
};
