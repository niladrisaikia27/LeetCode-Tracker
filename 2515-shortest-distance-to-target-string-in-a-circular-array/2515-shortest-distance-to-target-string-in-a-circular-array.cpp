class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = n; // Initialize with n, as the max possible distance is n-1
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                found = true;
                
                // Calculate the absolute difference between indices
                int absDist = std::abs(i - startIndex);
                
                // The shortest distance to this specific index 'i' in a circular array
                // is the minimum of going clockwise or counter-clockwise
                int currentShortest = std::min(absDist, n - absDist);
                
                // Update the overall minimum distance found so far
                minDistance = std::min(minDistance, currentShortest);
            }
        }

        return found ? minDistance : -1;
    }
};