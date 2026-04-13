class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDistance = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Check if the current element matches our target
            if (nums[i] == target) {
                // Calculate absolute distance and update minDistance if it's smaller
                int currentDistance = std::abs(i - start);
                
                if (currentDistance < minDistance) {
                    minDistance = currentDistance;
                }
                
                // Optimization: If we found a distance of 0, it can't get any smaller
                if (minDistance == 0) return 0;
            }
        }
        
        return minDistance;
    }
};