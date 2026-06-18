class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        vector<vector<int>> copyMatrix = matrix;

        for(int i=0; i<m; i++){
            int k = m-1;
            for(int j=0; j<m; j++){
                copyMatrix[i][j] = matrix[k][i];
                k--;
            }
        }
        matrix = copyMatrix;
    }
};