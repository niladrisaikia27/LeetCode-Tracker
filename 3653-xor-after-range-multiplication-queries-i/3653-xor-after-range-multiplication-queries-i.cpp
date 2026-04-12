class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        
        // Process each query
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int v = query[3];
            
            // Update the array elements as specified
            for (int idx = l; idx <= r; idx += k) {
                // Use 1LL to prevent integer overflow during multiplication
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        // Calculate the final bitwise XOR of all elements
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }
        
        return xorSum;
    }
};