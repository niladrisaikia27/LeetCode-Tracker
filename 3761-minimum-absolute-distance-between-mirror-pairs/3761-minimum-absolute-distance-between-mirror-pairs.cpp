class Solution {
private:
    // Helper function to reverse the digits of an integer
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
       // Map to store: reverse(nums[i]) -> most recent index i
        unordered_map<int, int> recent_reversed;
        int min_dist = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the current number is the reverse of a previously seen number
            if (recent_reversed.find(nums[i]) != recent_reversed.end()) {
                min_dist = min(min_dist, i - recent_reversed[nums[i]]);
            }
            
            // Add the reversed value of the current number to the map
            // Unconditionally overwrite to keep the most recent index (minimizing distance)
            recent_reversed[reverseNum(nums[i])] = i;
        }
        
        // If min_dist wasn't updated, no valid mirror pair was found
        return min_dist == INT_MAX ? -1 : min_dist; 
    }
};