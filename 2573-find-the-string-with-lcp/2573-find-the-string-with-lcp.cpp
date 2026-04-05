class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, ' ');
        char currentChar = 'a';

        // Phase 1: Greedily construct the lexicographically smallest string
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (currentChar > 'z') return ""; // More than 26 distinct characters needed
                
                for (int j = i; j < n; ++j) {
                    if (lcp[i][j] > 0) {
                        s[j] = currentChar;
                    }
                }
                currentChar++;
            }
        }

        // Phase 2: Validate the constructed string against the given lcp matrix
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int expectedLcp = 0;
                
                if (s[i] == s[j]) {
                    expectedLcp = 1 + ((i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] : 0);
                }
                
                if (lcp[i][j] != expectedLcp) {
                    return ""; // The matrix contains contradictions
                }
            }
        }

        return s;
    }
};