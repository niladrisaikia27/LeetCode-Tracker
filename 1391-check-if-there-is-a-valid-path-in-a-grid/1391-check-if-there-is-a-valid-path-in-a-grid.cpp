class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return false;
        int n = grid[0].size();
        
        // Direction vectors mapping: 0: Up, 1: Right, 2: Down, 3: Left
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        // Allowed outgoing directions for each street type (1-based index)
        // e.g., Street 1 connects Left(3) and Right(1)
        vector<vector<int>> allowed_dirs = {
            {},       // 0: Placeholder
            {1, 3},   // 1: Left-Right
            {0, 2},   // 2: Up-Down
            {2, 3},   // 3: Down-Left
            {1, 2},   // 4: Right-Down
            {0, 3},   // 5: Up-Left
            {0, 1}    // 6: Up-Right
        };
        
        // Visited matrix to prevent loops
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        // Start BFS at top-left cell
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // If we've reached the bottom-right cell, a valid path exists
            if (r == m - 1 && c == n - 1) {
                return true;
            }
            
            int curr_pipe = grid[r][c];
            
            // Explore all valid exits from the current pipe
            for (int dir : allowed_dirs[curr_pipe]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                // Check boundaries and whether we've already visited the adjacent cell
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int next_pipe = grid[nr][nc];
                    
                    // To connect, the next pipe must allow entry from the exact opposite direction.
                    // E.g., if we move Right (1), the next pipe must have an exit pointing Left (3).
                    // (dir + 2) % 4 mathematically flips 0<->2 (Up<->Down) and 1<->3 (Right<->Left).
                    int opposite_dir = (dir + 2) % 4;
                    
                    bool connects_back = false;
                    for (int next_dir : allowed_dirs[next_pipe]) {
                        if (next_dir == opposite_dir) {
                            connects_back = true;
                            break;
                        }
                    }
                    
                    // If the pipes link up properly, add to queue and mark as visited
                    if (connects_back) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        // If the queue empties without reaching the destination
        return false;
    }
};