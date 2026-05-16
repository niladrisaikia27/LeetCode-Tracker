class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int max_k = min(k, m + n);

        vector<vector<int>> prev_row(n, vector<int>(max_k + 1, -1));
        prev_row[0][0] = 0;
        
        for (int i = 0; i < m; ++i) {
            vector<vector<int>> curr_row(n, vector<int>(max_k + 1, -1));
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    curr_row[0] = prev_row[0];
                    continue;
                }
                
                int val = grid[i][j];
                int cell_cost = (val == 0) ? 0 : 1;
                int cell_score = val;
    
                for (int c = cell_cost; c <= max_k; ++c) {
                    int from_top = -1;
                    if (i > 0) {
                        from_top = prev_row[j][c - cell_cost];
                    }
                    
                    int from_left = -1;
                    if (j > 0) {
                        from_left = curr_row[j - 1][c - cell_cost];
                    }
                    
                    int max_prev = max(from_top, from_left);
                    if (max_prev != -1) {
                        curr_row[j][c] = max_prev + cell_score;
                    }
                }
            }
            prev_row = move(curr_row);
        }
        int max_score = -1;
        for (int c = 0; c <= max_k; ++c) {
            max_score = max(max_score, prev_row[n - 1][c]);
        }
        
        return max_score;
    }
};