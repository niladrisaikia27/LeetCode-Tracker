class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            // If count is 0, we pick the current number as the new candidate
            if (count == 0) {
                candidate = num;
            }

            // If the current number matches the candidate, increment; 
            // otherwise, decrement
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};