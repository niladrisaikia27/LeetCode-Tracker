class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0; i<numRows; i++){
            vector<int> tempList;
            int res = 1;
            tempList.push_back(res);
            for(int j=0; j<i; j++){
                res = res * (i - j);
                res = res/(j+1); 
                tempList.push_back(res);
            }
            ans.push_back(tempList);
        }
        return ans;
    }
};