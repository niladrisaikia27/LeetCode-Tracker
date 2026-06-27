class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int max_len = 1; 
        // Step 1: Handle the special case of 1s
        if (count.count(1)) {
            int c = count[1];
            max_len = max(max_len, (c % 2 == 0) ? c - 1 : c);
        }

        // Step 2: Handle all other numbers > 1
        for (auto& [x, freq] : count) {
            if (x == 1) continue;

            long long curr = x;
            int len = 0;

            // Keep building the layers of the mountain pattern
            while (count.count(curr) && count[curr] >= 2) {
                len += 2;
                curr = curr * curr; // Move to the next square
            }

            // Check if the current element can act as the peak
            if (count.count(curr) && count[curr] >= 1) {
                len += 1;
            } else {
                // If it can't be the peak, the previous element must be the peak
                // We subtract 1 because the last element added 2 but can only contribute 1 as a peak
                len -= 1;
            }
            max_len = max(max_len, len);
        }

        return max_len;
    }
};