class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n ==1) 
            return n;

        int maxL = 1;
        int count = 1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                continue;
            }

            else if(nums[i]+1 == nums[i+1]){
                count++;
                maxL = max(count, maxL);
            }
        
            else{
                count = 1;
            }
        }
        return maxL;
    }
};