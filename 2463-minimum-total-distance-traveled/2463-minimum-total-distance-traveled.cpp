class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by their positions to ensure optimal sequential matching
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // Flatten the factories into individual available slots
        vector<int> flat_factories;
        for (const auto& f : factory) {
            for (int i = 0; i < f[1]; ++i) {
                flat_factories.push_back(f[0]);
            }
        }
        
        int r = robot.size();
        int f_size = flat_factories.size();
        
        // dp represents the minimum distance to satisfy robots using up to j factory slots.
        // Base case: 0 robots require 0 distance.
        vector<long long> dp(f_size + 1, 0);
        
        // Process each robot one by one
        for (int i = 1; i <= r; ++i) {
            // Initialize current row with a very large number (infinity representation)
            vector<long long> next_dp(f_size + 1, 1e18); 
            
            // To satisfy i robots, we need at least i factory slots
            for (int j = i; j <= f_size; ++j) {
                // Calculate distance between the current robot and the current factory slot
                long long distance = abs(static_cast<long long>(robot[i - 1]) - flat_factories[j - 1]);
                
                // Option 1: Skip this factory slot (next_dp[j - 1])
                // Option 2: Use this factory slot for the current robot (dp[j - 1] + distance)
                next_dp[j] = min(next_dp[j - 1], dp[j - 1] + distance);
            }
            // Move to the next robot
            dp = move(next_dp);
        }
        
        // The answer is the minimum distance to satisfy all 'r' robots using all 'f_size' slots
        return dp[f_size];
    }
};