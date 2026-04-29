class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // pref[i][j] will store the sum of grid[0...j-1][i] (prefix sum of column i)
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pref[i][j + 1] = pref[i][j] + grid[j][i];
            }
        }
        
        const long long INF = 1e15; // Safe infinity to prevent underflow
        
        // dp[p][h]: max score given previous col's height is `p` and current col's height is `h`
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -INF));
        
        // Base case: before column 0, the imaginary column -1 has height 0
        for (int h = 0; h <= n; ++h) {
            dp[0][h] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, -INF));
            
            for (int h = 0; h <= n; ++h) {
                // Precompute prefix maxes for p <= k
                vector<long long> pref_max(n + 1, -INF);
                pref_max[0] = dp[0][h];
                for (int p = 1; p <= n; ++p) {
                    pref_max[p] = max(pref_max[p - 1], dp[p][h]);
                }
                
                // Precompute suffix maxes for p > k
                vector<long long> suff_max(n + 2, -INF);
                for (int p = n; p >= 0; --p) {
                    long long cost_p = max(0LL, pref[i][p] - pref[i][h]);
                    suff_max[p] = max(suff_max[p + 1], dp[p][h] + cost_p);
                }
                
                // Calculate next_dp transitions in O(1) using precomputations
                for (int k = 0; k <= n; ++k) {
                    long long cost_k = max(0LL, pref[i][k] - pref[i][h]);
                    
                    // Case 1: p <= k -> maximum adjacent height is k
                    long long val1 = pref_max[k] + cost_k;
                    
                    // Case 2: p > k -> maximum adjacent height is p
                    long long val2 = suff_max[k + 1];
                    
                    next_dp[h][k] = max(val1, val2);
                }
            }
            dp = next_dp;
        }
        
        long long ans = 0;
        
        // Final imaginary column `n` has height 0
        for (int h = 0; h <= n; ++h) {
            ans = max(ans, dp[h][0]);
        }
        
        return ans;
    }
};