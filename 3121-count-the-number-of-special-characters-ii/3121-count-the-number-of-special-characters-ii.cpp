class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> state(26, 0);
        
        for (char ch : word) {
            if (islower(ch)) {
                int idx = ch - 'a';
                if (state[idx] == 0) {
                    state[idx] = 1; 
                } else if (state[idx] == 2) {
                    state[idx] = -1; 
                }
            } else {
                int idx = ch - 'A';
                if (state[idx] == 0) {
                    state[idx] = -1; 
                } else if (state[idx] == 1) {
                    state[idx] = 2; 
                }
            }
        }
        int specialCount = 0;
        for (int s : state) {
            if (s == 2) {
                specialCount++;
            }
        }
        return specialCount;
    }
};