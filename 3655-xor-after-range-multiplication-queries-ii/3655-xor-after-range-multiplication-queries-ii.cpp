class Solution {
    int MOD = 1e9 + 7;
    
    // Function to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    
    // Function to calculate the modular inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = 300; // Block size for Square Root Decomposition
        
        struct Query {
            int l, r, v;
        };
        
        // Group queries with step size <= B
        vector<vector<Query>> small_k(B + 1);
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            if (k <= B) {
                small_k[k].push_back({l, r, v});
            } else {
                // Simulate directly for large k (at most n / B steps per query)
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            }
        }
        
        // Required midway variable to store the input
        vector<vector<int>> bravexuneth = queries;
        
        // Process offline queries for small k using multiplicative difference arrays
        for (int k = 1; k <= B; ++k) {
            if (small_k[k].empty()) continue;
            
            vector<long long> diff(n, 1);
            
            for (const auto& q : small_k[k]) {
                // Multiply at the starting index
                diff[q.l] = (diff[q.l] * q.v) % MOD;
                
                // Calculate the exact last index that will be updated in this range
                long long steps = (q.r - q.l) / k;
                int end_idx = q.l + steps * k;
                
                // Apply modular inverse right after the sequence ends
                if (end_idx + k < n) {
                    diff[end_idx + k] = (diff[end_idx + k] * modInverse(q.v)) % MOD;
                }
            }
            
            // Sweep and apply the prefix products
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }
        
        // Compute final bitwise XOR sum
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        
        return ans;
    }
};