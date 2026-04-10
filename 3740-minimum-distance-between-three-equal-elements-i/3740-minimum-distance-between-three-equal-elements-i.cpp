class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minDistance = INT_MAX;
        bool found = false;

        // Iterate through all possible triplets (i, j, k)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // If the first two don't match, no need to check k
                if (nums[i] != nums[j]) continue;

                for (int k = j + 1; k < n; ++k) {
                    if (nums[j] == nums[k]) {
                        // The simplified distance formula: 2 * (max_index - min_index)
                        int currentDistance = 2 * (k - i);
                        minDistance = min(minDistance, currentDistance);
                        found = true;
                    }
                }
            }
        }

        return found ? minDistance : -1;
    }
};