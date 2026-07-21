class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Effective shifts needed
        k = k % total;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int old_index = i * n + j;
                int new_index = (old_index + k) % total;
                
                int new_r = new_index / n;
                int new_c = new_index % n;
                
                result[new_r][new_c] = grid[i][j];
            }
        }
        
        return result;
    }
};