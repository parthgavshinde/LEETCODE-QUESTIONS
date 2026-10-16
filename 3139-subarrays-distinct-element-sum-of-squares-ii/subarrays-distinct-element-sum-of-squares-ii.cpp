class Solution {
    struct Node {
        long long sum_sq = 0;
        long long sum_c = 0;
        long long lazy = 0;
    };
    vector<Node> tree;
    long long MOD = 1e9 + 7;

    void apply(int node, int l, int r, long long v) {
        long long len = r - l + 1;
        tree[node].sum_sq = (tree[node].sum_sq + 2 * v % MOD * tree[node].sum_c % MOD + v * v % MOD * len % MOD) % MOD;
        tree[node].sum_c = (tree[node].sum_c + v * len % MOD) % MOD;
        tree[node].lazy = (tree[node].lazy + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            int mid = l + (r - l) / 2;
            long long v = tree[node].lazy;
            apply(2 * node, l, mid, v);
            apply(2 * node + 1, mid + 1, r, v);
            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, v);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, v);
        update(2 * node + 1, mid + 1, r, ql, qr, v);
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
        tree[node].sum_c = (tree[2 * node].sum_c + tree[2 * node + 1].sum_c) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n + 1);
        unordered_map<int, int> last_occurrence;
        long long total_sum = 0;

        for (int i = 0; i < n; i++) {
            // Find where this number last appeared
            int start_idx = last_occurrence.count(nums[i]) ? last_occurrence[nums[i]] + 1 : 1;
            
            // Increment the distinct count for all subarrays ending at 'i' and starting between start_idx and i+1
            update(1, 1, n, start_idx, i + 1, 1);
            
            // Add the sum of squares of all valid subarrays ending at 'i' to the total
            total_sum = (total_sum + tree[1].sum_sq) % MOD;
            
            // Update the last seen position (using 1-based indexing for the segment tree)
            last_occurrence[nums[i]] = i + 1;
        }
        
        return total_sum;
    }
};
