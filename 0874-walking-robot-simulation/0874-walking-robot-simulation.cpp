class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        // 0 = North, 1 = East, 2 = South, 3 = West
        int dir = 0; 

        // Hash set for O(1) obstacle lookup
        unordered_set<long long> obsSet;
        for (const auto& obs : obstacles) {
            // Offset by 30000 to handle negatives, pack into a single 64-bit integer
            long long hashVal = ((long long)(obs[0] + 30000) << 16) | (obs[1] + 30000);
            obsSet.insert(hashVal);
        }

        int x = 0, y = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left 90 degrees
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                // Turn right 90 degrees
                dir = (dir + 1) % 4;
            } else {
                // Move forward step-by-step
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    // Check if the next step is an obstacle
                    long long hashVal = ((long long)(nx + 30000) << 16) | (ny + 30000);
                    if (obsSet.count(hashVal)) {
                        break; // Stop moving, proceed to next command
                    }
                    
                    // Update position
                    x = nx;
                    y = ny;
                    
                    // Track maximum squared distance
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};