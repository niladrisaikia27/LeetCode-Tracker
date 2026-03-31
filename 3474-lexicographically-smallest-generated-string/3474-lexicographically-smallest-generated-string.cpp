class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;
        
        // Initialize the result string with null characters
        string res(len, '\0');

        // Step 1: Satisfy all 'T' conditions (fixed characters)
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != '\0' && res[i + j] != str2[j]) {
                        // Conflict: Overlapping 'T's require different characters
                        return "";
                    }
                    res[i + j] = str2[j];
                }
            }
        }

        // Step 2: Track the "last chance" free index for every 'F' window
        // and check if any 'F' windows are already impossible (fully fixed and matching)
        vector<vector<int>> last_chance_for(len);
        for (int i = 0; i < n; ++i) {
            int last_unset_idx = -1;
            for (int j = m - 1; j >= 0; --j) {
                if (res[i + j] == '\0') {
                    last_unset_idx = i + j;
                    break;
                }
            }

            if (last_unset_idx != -1) {
                // The window has free slots; register it at its last free index
                last_chance_for[last_unset_idx].push_back(i);
            } else if (str1[i] == 'F') {
                // Window is fully fixed. Check if it violates the 'F' condition.
                bool match = true;
                for (int j = 0; j < m; ++j) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return ""; 
            }
        }

        // Step 3: Greedily fill remaining slots from left to right
        for (int k = 0; k < len; ++k) {
            if (res[k] == '\0') {
                vector<bool> forbidden(26, false);
                
                // Check all 'F' windows for which index 'k' is the last free slot
                for (int i : last_chance_for[k]) {
                    if (str1[i] == 'F') {
                        // Check if all OTHER characters in the window already match str2
                        bool others_match = true;
                        for (int j = 0; j < m; ++j) {
                            int current_idx = i + j;
                            if (current_idx == k) continue; 
                            if (res[current_idx] != str2[j]) {
                                others_match = false;
                                break;
                            }
                        }
                        // If everything else matches, we cannot pick str2[k-i] for res[k]
                        if (others_match) {
                            forbidden[str2[k - i] - 'a'] = true;
                        }
                    }
                }
                
                // Pick the lexicographically smallest allowed character ('a', 'b', etc.)
                for (int c = 0; c < 26; ++c) {
                    if (!forbidden[c]) {
                        res[k] = (char)('a' + c);
                        break;
                    }
                }
            }
        }

        return res;
    }
};