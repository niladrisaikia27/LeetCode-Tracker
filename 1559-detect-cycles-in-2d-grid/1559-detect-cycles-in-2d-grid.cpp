class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Direction vectors for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Check every cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the cell hasn't been visited, start a new DFS from it
                if (!visited[i][j]) {
                    // Pass -1, -1 as the initial parent coordinates
                    if (dfs(grid, visited, i, j, -1, -1, dr, dc)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    private:
    bool dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, 
             int r, int c, int pr, int pc, const int dr[], const int dc[]) {
        
        visited[r][c] = true;
        char ch = grid[r][c];
        
        // Explore all 4 adjacent directions
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check bounds and if the adjacent cell has the same character
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == ch) {
                
                // If it is already visited, check if it's the parent cell
                if (visited[nr][nc]) {
                    if (nr != pr || nc != pc) {
                        return true; // Cycle detected
                    }
                } else {
                    // If not visited, recursively call DFS
                    if (dfs(grid, visited, nr, nc, r, c, dr, dc)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};