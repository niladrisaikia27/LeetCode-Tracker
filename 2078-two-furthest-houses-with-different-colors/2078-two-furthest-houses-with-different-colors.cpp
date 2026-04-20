class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;

        // Case 1: Compare the first house with houses from the end
        for (int i = n - 1; i > 0; --i) {
            if (colors[i] != colors[0]) {
                maxDist = std::max(maxDist, i);
                break;
            }
        }

        // Case 2: Compare the last house with houses from the beginning
        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] != colors[n - 1]) {
                maxDist = std::max(maxDist, (n - 1) - i);
                break;
            }
        }

        return maxDist;
    }
};