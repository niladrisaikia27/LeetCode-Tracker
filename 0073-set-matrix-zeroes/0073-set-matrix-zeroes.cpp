class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();      // row
        int n = matrix[0].size();   // column
        vector<vector<int>> copyMatrix = matrix;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    //set entire row to -1
                    for(int k = 0; k<n; k++){
                            copyMatrix[i][k] = 0;
                    }
                    //set entire column to -1
                    for(int k=0; k<m; k++){
                            copyMatrix[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(copyMatrix[i][j] == 0){
                    copyMatrix[i][j] = 0;
                }
            }
        }
        matrix = copyMatrix;
    }
};