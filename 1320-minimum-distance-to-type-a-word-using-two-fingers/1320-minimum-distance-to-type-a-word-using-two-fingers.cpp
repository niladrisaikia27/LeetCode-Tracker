class Solution {
private:
    // Helper function to calculate the Manhattan distance between two characters.
    // The grid has 6 columns.
    int getDistance(int a, int b) {
        if (a == 26) return 0; // 26 represents a "free" finger, moving it costs 0.
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(int idx, int otherFinger, const string& word, vector<vector<int>>& memo) {
        // Base case: If we've typed the whole word, the cost is 0.
        if (idx == word.length()) {
            return 0;
        }

        // Return memoized result if it exists.
        if (memo[idx][otherFinger] != -1) {
            return memo[idx][otherFinger];
        }

        int prevFinger = word[idx - 1] - 'A';
        int currChar = word[idx] - 'A';

        // Option 1: Move the finger that typed the previous character to the current character.
        // The 'otherFinger' stays where it is.
        int cost1 = getDistance(prevFinger, currChar) + solve(idx + 1, otherFinger, word, memo);

        // Option 2: Move the 'otherFinger' to the current character.
        // The finger that typed the previous character now becomes the new 'otherFinger'.
        int cost2 = getDistance(otherFinger, currChar) + solve(idx + 1, prevFinger, word, memo);

        // Store the minimum of both options and return.
        return memo[idx][otherFinger] = min(cost1, cost2);
    }

public:
    int minimumDistance(string word) {
        int n = word.length();
        
        // memo[i][j] stores the min cost to type the suffix of word starting at index i,
        // given that one finger is at word[i-1] and the other finger is at character j.
        // Size is n x 27 (0-25 for 'A'-'Z', 26 for an initially unplaced finger).
        vector<vector<int>> memo(n, vector<int>(27, -1));
        
        // Start from index 1. The first finger is implicitly placed at word[0] for free.
        // The other finger is unplaced (state 26).
        return solve(1, 26, word, memo);
    }
};