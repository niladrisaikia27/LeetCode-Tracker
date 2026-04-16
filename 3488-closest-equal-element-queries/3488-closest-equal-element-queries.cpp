class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Store pairs of {value, original_index}
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        
        // Sort to group identical values together, and naturally sort their indices
        sort(arr.begin(), arr.end());
        
        // Array to store the precalculated answers for each index
        vector<int> minDist(n, -1);
        
        int i = 0;
        while (i < n) {
            int j = i;
            // Find the range [i, j-1] where elements have the same value
            while (j < n && arr[j].first == arr[i].first) {
                j++;
            }
            
            int count = j - i;
            if (count > 1) {
                for (int k = i; k < j; k++) {
                    int current_idx = arr[k].second;
                    
                    // The closest occurrence is always adjacent in the sorted indices.
                    // Wrap around to treat the first and last instances as adjacent.
                    int prev_k = (k == i) ? j - 1 : k - 1;
                    int next_k = (k == j - 1) ? i : k + 1;
                    
                    int prev_idx = arr[prev_k].second;
                    int next_idx = arr[next_k].second;
                    
                    auto get_dist = [&](int a, int b) {
                        int dist = abs(a - b);
                        return min(dist, n - dist);
                    };
                    
                    // Min distance is the minimum of going left vs going right to the nearest match
                    minDist[current_idx] = min(get_dist(current_idx, prev_idx), get_dist(current_idx, next_idx));
                }
            }
            // Move to the next unique value
            i = j;
        }
        
        // Construct the final answer array using the precomputed distances
        vector<int> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
            ans.push_back(minDist[q]);
        }
        
        return ans;
    }
};