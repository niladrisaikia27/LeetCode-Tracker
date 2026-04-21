class Solution {
private:
        vector<int> parent;
    
    // DSU Find with path compression
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    
    // DSU Union
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        
        // Initialize DSU, each node is its own parent initially
        iota(parent.begin(), parent.end(), 0);
        
        // 1. Group indices into connected components
        for (const auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
        
        // 2. Map structure: root_of_component -> (element -> frequency)
        unordered_map<int, unordered_map<int, int>> componentElementCounts;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            componentElementCounts[root][source[i]]++;
        }
        
        // 3. Match target elements with available source elements in the same component
        int matchedElements = 0;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            
            // If the element exists in the component and hasn't been entirely used up
            if (componentElementCounts[root][target[i]] > 0) {
                componentElementCounts[root][target[i]]--;
                matchedElements++;
            }
        }
        
        // 4. The minimum Hamming distance is elements that couldn't be matched
        return n - matchedElements;
    }
};