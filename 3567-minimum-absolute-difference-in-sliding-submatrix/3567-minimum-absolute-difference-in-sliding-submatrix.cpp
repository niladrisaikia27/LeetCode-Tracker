class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Result dimensions will be (m - k + 1) x (n - k + 1)
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        // Iterate through all possible top-left corners of k x k submatrices
        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int> submatrix_elements;
                submatrix_elements.reserve(k * k);
                
                // Collect all elements within the current k x k submatrix
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        submatrix_elements.push_back(grid[r][c]);
                    }
                }
                
                // Sort the collected elements
                sort(submatrix_elements.begin(), submatrix_elements.end());
                
                // Erase duplicates to keep only distinct elements
                submatrix_elements.erase(
                    unique(submatrix_elements.begin(), submatrix_elements.end()), 
                    submatrix_elements.end()
                );
                
                // If there is only 1 distinct element, the difference defaults to 0
                if (submatrix_elements.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int min_diff = 1e9; // Start with a large value
                    
                    // Find the minimum difference between adjacent sorted distinct elements
                    for (size_t idx = 1; idx < submatrix_elements.size(); ++idx) {
                        min_diff = min(min_diff, submatrix_elements[idx] - submatrix_elements[idx - 1]);
                    }
                    ans[i][j] = min_diff;
                }
            }
        }
        
        return ans;
    }
};