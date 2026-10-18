#include <vector>

using namespace std;

class Solution {
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;
    
    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m < 3) return 1; // Base case: arrays of length 0, 1, or 2 have 1 valid structure
        
        vector<int> leftNodes, rightNodes;
        int root = nums[0];
        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }
        
        long long leftWays = dfs(leftNodes) % mod;
        long long rightWays = dfs(rightNodes) % mod;
        
        // Calculate combinations and multiply subtrees
        long long combinations = table[m - 1][leftNodes.size()];
        return (((combinations * leftWays) % mod) * rightWays) % mod;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute Pascal's triangle for nCr calculations
        table.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            table[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        // Subtract 1 to exclude the original array structure
        return (dfs(nums) - 1 + mod) % mod;
    }
};
