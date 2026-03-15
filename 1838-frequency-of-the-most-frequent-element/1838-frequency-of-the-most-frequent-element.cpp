class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0;
        long long totalsum = 0;
        int maxFreq = 0;
        for(int right = 0; right<nums.size(); right++){
            totalsum += nums[right];
            while((long long)nums[right] * (right - left + 1) - totalsum > k){
                totalsum -= nums[left];
                left++;
            } 
            maxFreq = max(maxFreq,(int)(right - left +1));
        }
        return maxFreq;
    }
   
};