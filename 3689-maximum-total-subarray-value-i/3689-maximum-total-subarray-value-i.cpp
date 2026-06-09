class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        long long max_diff = *max_it - *min_it;
        
        return max_diff * k;
    }
};