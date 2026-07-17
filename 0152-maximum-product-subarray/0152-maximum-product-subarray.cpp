class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int global_max = nums[0];
        int current_max = nums[0];
        int current_min = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int val = nums[i];
            
            // If the current value is negative, multiplying by it swaps 
            // the potential maximum and minimum values.
            if (val < 0) {
                std::swap(current_max, current_min);
            }
            
            // Decide whether to start a new subarray or extend the existing one
            current_max = std::max(val, current_max * val);
            current_min = std::min(val, current_min * val);
            
            // Update the global maximum achieved so far
            global_max = std::max(global_max, current_max);
        }
        
        return global_max;
    }
};