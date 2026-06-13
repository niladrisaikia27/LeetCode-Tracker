class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";
        
        for (const string& word : words) {
            int currentWeight = 0;
            for (char c : word) {
                currentWeight += weights[c - 'a'];
            }
            int modVal = currentWeight % 26;
            result.push_back(char('z' - modVal));
        }
        return result;
    }
};