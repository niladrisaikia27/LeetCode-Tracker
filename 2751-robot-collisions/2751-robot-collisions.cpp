class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Create an array of original indices to keep track of the original order
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); 
        
        // Sort the indices based on the starting positions from left to right
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        vector<int> stack; // Will store the indices of the surviving robots
        
        for (int i : indices) {
            if (directions[i] == 'R') {
                // Moving right, push to stack to potentially collide with future 'L' robots
                stack.push_back(i);
            } else {
                // Moving left, process potential collisions
                bool survived = true;
                
                while (!stack.empty() && directions[stack.back()] == 'R') {
                    int top_i = stack.back();
                    
                    if (healths[top_i] > healths[i]) {
                        // The robot moving Right wins
                        healths[top_i] -= 1;
                        healths[i] = 0; // Current robot dies
                        survived = false;
                        break;
                    } else if (healths[top_i] < healths[i]) {
                        // The robot moving Left wins
                        healths[i] -= 1;
                        healths[top_i] = 0; // Robot moving Right dies
                        stack.pop_back();
                    } else {
                        // Both have the same health and destroy each other
                        healths[i] = 0;
                        healths[top_i] = 0;
                        stack.pop_back();
                        survived = false;
                        break;
                    }
                }
                
                // If the left-moving robot survived all right-moving robots, add it to the stack
                if (survived) {
                    stack.push_back(i);
                }
            }
        }
        
        // Collect the healths of all surviving robots in their original given order
        vector<int> result;
        for (int h : healths) {
            if (h > 0) {
                result.push_back(h);
            }
        }
        
        return result;
    }
};