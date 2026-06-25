class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_subarrays = 0;
        
        for (int i = 0; i < n; ++i) {
            int balance = 0;
            for (int j = i; j < n; ++j) {
                balance += (nums[j] == target) ? 1 : -1;
                // If balance is strictly positive, target is the majority element
                if (balance > 0) {
                    total_subarrays++;
                }
            }
        }
        
        return total_subarrays;
    }
};