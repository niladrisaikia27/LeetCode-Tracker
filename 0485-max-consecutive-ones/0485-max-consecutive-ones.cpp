class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, num = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                num = max(num,count);
                count = 0;
            }    
        }
        return max(num, count);
    }
};