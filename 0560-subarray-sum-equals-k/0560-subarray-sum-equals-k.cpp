class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int count = 0;
        unordered_map<int, int> mpp;

        mpp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;

            if(mpp.find(remove) != mpp.end()){
                count += mpp[remove];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};