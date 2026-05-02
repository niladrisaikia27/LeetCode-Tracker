class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);
        
        unordered_map<int, vector<int>> valToIndices;
        
        for (int i = 0; i < n; ++i) {
            valToIndices[nums[i]].push_back(i);
        }
        for (auto const& [val, indices] : valToIndices) {
            long long totalSum = 0;
            for (int idx : indices) {
                totalSum += idx;
            }
            long long prefixSum = 0;
            int k = indices.size();
            
            for (int i = 0; i < k; ++i) {
                long long p_i = indices[i];
                
                long long leftCount = i;
                long long leftSum = (leftCount * p_i) - prefixSum;
                
                long long rightCount = k - 1 - i;
                long long rightSum = (totalSum - prefixSum - p_i) - (rightCount * p_i);
                
                arr[p_i] = leftSum + rightSum;
                prefixSum += p_i;
            }
        }
        
        return arr;
    }
};