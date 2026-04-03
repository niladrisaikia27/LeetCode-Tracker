class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // Pair up robot positions and their bullet distances, then sort by position
        vector<pair<int, int>> rob(n);
        for(int i = 0; i < n; ++i) {
            rob[i] = {robots[i], distance[i]};
        }
        sort(rob.begin(), rob.end());
        
        // Sort walls for binary searching
        sort(walls.begin(), walls.end());

        vector<int> filtered_walls;
        int pre_destroyed = 0;
        int r_idx = 0;

        // Pre-process walls: count walls exactly on top of robots and filter them out
        // This avoids double-counting and simplifies range logic.
        for(int w : walls) {
            while(r_idx < n && rob[r_idx].first < w) {
                r_idx++;
            }
            if(r_idx < n && rob[r_idx].first == w) {
                pre_destroyed++;
            } else {
                filtered_walls.push_back(w);
            }
        }

        // Helper lambda to count walls in range [L, R]
        // Explicitly use std::distance to avoid conflict with the 'distance' vector
        auto count_walls = [&](int L, int R) -> int {
            if (L > R) return 0;
            auto it1 = lower_bound(filtered_walls.begin(), filtered_walls.end(), L);
            auto it2 = upper_bound(filtered_walls.begin(), filtered_walls.end(), R);
            return (int)std::distance(it1, it2);
        };

        // dp_L: max walls destroyed up to robot i, with robot i shooting LEFT
        // dp_R: max walls destroyed up to robot i, with robot i shooting RIGHT
        int dp_L = count_walls(rob[0].first - rob[0].second, rob[0].first);
        int dp_R = 0;

        for(int i = 1; i < n; ++i) {
            int prev_L = dp_L;
            int prev_R = dp_R;

            // Define segment bounds between robot[i-1] and robot[i]
            int shoot_right_end = min(rob[i-1].first + rob[i-1].second, rob[i].first);
            int shoot_left_start = max(rob[i].first - rob[i].second, rob[i-1].first);

            int w_R = count_walls(rob[i-1].first, shoot_right_end);
            int w_L = count_walls(shoot_left_start, rob[i].first);
            
            // If both robots' bullets cover the same section, we find the overlap
            int overlap_start = max(rob[i-1].first, shoot_left_start);
            int overlap_end = min(rob[i].first, shoot_right_end);
            int w_overlap = (overlap_start <= overlap_end) ? count_walls(overlap_start, overlap_end) : 0;

            // Transition:
            // To compute dp_L (current robot shoots left):
            // 1. Prev robot shot left: just add current left shot.
            // 2. Prev robot shot right: add current left, but subtract overlap to avoid double-counting.
            dp_L = max(prev_L + w_L, prev_R + w_R + w_L - w_overlap);
            
            // To compute dp_R (current robot shoots right):
            // We only count walls to the LEFT of the current robot for this state.
            // 1. Prev robot shot left: current robot adds nothing to the previous segments.
            // 2. Prev robot shot right: current robot adds the previous right shot.
            dp_R = max(prev_L, prev_R + w_R);
        }

        // Finally, add the walls destroyed by the very last robot shooting right
        int final_right_shot = count_walls(rob[n-1].first, rob[n-1].first + rob[n-1].second);
        
        return max(dp_L, dp_R + final_right_shot) + pre_destroyed;
    }
};