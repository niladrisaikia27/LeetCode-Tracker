class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int left=0, curr=0; curr<n; curr++){
            if(nums[curr]!=0){
                swap(nums[left], nums[curr]);
                left++;
            }
        }
    }
};