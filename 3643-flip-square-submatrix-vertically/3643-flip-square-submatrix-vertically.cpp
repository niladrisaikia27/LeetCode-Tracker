class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = 0; i < k / 2; ++i) {
            int topRowIndex = x + i;
            int bottomRowIndex = x + k - 1 - i;

            // Iterate through each column within the submatrix's width
            for (int j = y; j < y + k; ++j) {
                // Swap elements between the top row and the bottom row
                swap(grid[topRowIndex][j], grid[bottomRowIndex][j]);
            }
        }
        
        return grid;
    }
};