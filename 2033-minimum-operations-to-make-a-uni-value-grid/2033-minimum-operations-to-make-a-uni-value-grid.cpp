class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }
        int rem = nums[0] % x;
        for (int num : nums) {
            if (num % x != rem) {
                return -1; 
            }
        }
        sort(nums.begin(), nums.end());
        
        int totalElements = nums.size();
        int median = nums[totalElements / 2];
        int minOps = 0;
        for (int num : nums) {
            minOps += abs(num - median) / x;
        }
        return minOps;
    }
};