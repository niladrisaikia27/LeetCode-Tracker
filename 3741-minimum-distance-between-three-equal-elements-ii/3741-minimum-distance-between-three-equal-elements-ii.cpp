class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = INT_MAX;
        
        // Arrays to track the most recent two indices of each value
        // Sized n + 1 because the constraints state 1 <= nums[i] <= n
        vector<int> last_seen(n + 1, -1);
        vector<int> second_last_seen(n + 1, -1);
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            // If we have seen this number at least twice before
            if (second_last_seen[val] != -1) {
                // Calculate distance and update minimum
                int current_dist = 2 * (i - second_last_seen[val]);
                min_dist = min(min_dist, current_dist);
            }
            
            // Shift the recent indices to accommodate the new occurrence
            second_last_seen[val] = last_seen[val];
            last_seen[val] = i;
        }
        
        // If min_dist wasn't updated, no good tuple exists
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};