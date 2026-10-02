#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, index}
    int index;

    StockSpanner() {
        index = -1;
    }

    int next(int price) {
        index++;

        // Pop all prices <= current price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans;
        if (st.empty()) {
            ans = index + 1; // Span covers from start
        } else {
            ans = index - st.top().second; // Span between current and last greater
        }

        // Push current price with its index
        st.push({price, index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */