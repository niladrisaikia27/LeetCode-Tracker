class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int maxDist = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            // j must be at least i to form a valid pair (distance >= 0)
            if (i > j) {
                j = i;
            }

            // If within bounds and the condition is satisfied
            if (j < n2 && nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++; // Move j to the right to try and increase the distance
            } else {
                i++; // The pair is invalid, move i to the right for a smaller nums1 value
            }
        }

        return maxDist;
    }
};