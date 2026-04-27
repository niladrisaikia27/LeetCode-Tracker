class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        vector<vector<int>> allowed_dirs = {
            {},       
            {1, 3},   
            {0, 2},   
            {2, 3},   
            {1, 2},   
            {0, 3},   
            {0, 1}    
        };
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) {
                return true;
            }
            
            int curr_pipe = grid[r][c];
            
            for (int dir : allowed_dirs[curr_pipe]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int next_pipe = grid[nr][nc];
                    
                    int opposite_dir = (dir + 2) % 4;
                    
                    bool connects_back = false;
                    for (int next_dir : allowed_dirs[next_pipe]) {
                        if (next_dir == opposite_dir) {
                            connects_back = true;
                            break;
                        }
                    }
                    
                    if (connects_back) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
};