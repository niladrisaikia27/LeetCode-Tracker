class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if (intervals.empty()) return {};

        // Step 1: Find the maximum start coordinate to size our bucket array
        int max_val = 0;
        for (const auto& inv : intervals) {
            max_val = max(max_val, inv[0]);
        }

        // Step 2: Track the maximum end coordinate achieved by any interval starting at index i
        vector<int> max_end(max_val + 1, -1);
        for (const auto& inv : intervals) {
            max_end[inv[0]] = max(max_end[inv[0]], inv[1]);
        }

        vector<vector<int>> merged;
        int current_start = -1;
        int current_end = -1;

        // Step 3: Traverse the bucket array to merge linearly
        for (int i = 0; i <= max_val; ++i) {
            if (max_end[i] == -1) continue; // No interval starts at coordinate i

            // If it's the first interval we're processing
            if (current_start == -1) {
                current_start = i;
                current_end = max_end[i];
            } 
            // If the current start point is within the range of our active interval, merge
            else if (i <= current_end) {
                current_end = max(current_end, max_end[i]);
            } 
            // Disjoint interval found: push the old one and reset tracking variables
            else {
                merged.push_back({current_start, current_end});
                current_start = i;
                current_end = max_end[i];
            }
        }

        // Push the final tracking interval into the result
        if (current_start != -1) {
            merged.push_back({current_start, current_end});
        }

        return merged;
    }
};