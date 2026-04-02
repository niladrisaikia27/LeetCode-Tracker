class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k] -> Max profit at (i, j) using k neutralizations
        // Using long long to prevent overflow and initializing with a very small value
        long long INF = 1e16;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(3, -INF)));

        // Base Case: Starting cell (0, 0)
        for (int k = 0; k < 3; ++k) {
            // Option 1: Don't neutralize the start cell
            dp[0][0][k] = coins[0][0];
            // Option 2: Neutralize the start cell if it's a robber and we have uses left
            if (k > 0 && coins[0][0] < 0) {
                dp[0][0][k] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; // Already handled base case

                for (int k = 0; k < 3; ++k) {
                    // Get values from Top and Left
                    long long from_top = (i > 0) ? dp[i - 1][j][k] : -INF;
                    long long from_left = (j > 0) ? dp[i][j - 1][k] : -INF;
                    
                    // Case 1: Enter cell normally (gain coins or lose to robber)
                    dp[i][j][k] = max(from_top, from_left) + coins[i][j];

                    // Case 2: Neutralize this cell (only if it's a robber and k > 0)
                    if (k > 0 && coins[i][j] < 0) {
                        long long from_top_prev = (i > 0) ? dp[i - 1][j][k - 1] : -INF;
                        long long from_left_prev = (j > 0) ? dp[i][j - 1][k - 1] : -INF;
                        
                        // We take the max of "staying as is" or "neutralizing current cell"
                        dp[i][j][k] = max(dp[i][j][k], max(from_top_prev, from_left_prev));
                    }
                }
            }
        }

        // The answer is the best profit at the bottom-right using any number of neutralizations (up to 2)
        return (int)max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};