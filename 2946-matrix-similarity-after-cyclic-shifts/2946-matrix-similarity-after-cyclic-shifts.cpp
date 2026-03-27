class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // A cyclic shift of k is equivalent to a shift of k % n.
        // If k is a multiple of n, the matrix always remains the same.
        int shift = k % n;
        if (shift == 0) return true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // For any cyclic shift of 'shift' positions to result in 
                // the same row, the element at index j must match the 
                // element at the shifted index.
                if (mat[i][j] != mat[i][(j + shift) % n]) {
                    return false;
                }
            }
        }

        return true;
    }
};