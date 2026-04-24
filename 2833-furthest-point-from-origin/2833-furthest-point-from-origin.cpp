class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCount = 0;
        int rCount = 0;
        int wildcards = 0;

        for (char c : moves) {
            if (c == 'L') {
                lCount++;
            } else if (c == 'R') {
                rCount++;
            } else {
                wildcards++;
            }
        }

        // The logic: find the difference between L and R, 
        // then add all wildcards to that absolute difference.
        return std::abs(lCount - rCount) + wildcards;
    }
};