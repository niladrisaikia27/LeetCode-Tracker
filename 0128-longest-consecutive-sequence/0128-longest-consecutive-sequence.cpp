class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set numSet(nums.begin(), nums.end());
        int maxCount = 0;

        for(int num : numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int currentNum = num;
                int count = 1;

                while(numSet.find(currentNum + 1) != numSet.end()){
                    currentNum++;
                    count++;
                }

                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
};