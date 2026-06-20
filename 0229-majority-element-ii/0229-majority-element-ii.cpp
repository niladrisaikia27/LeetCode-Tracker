class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> res;
        int n = nums.size();
        //count frequencies of each element
        for(int num : nums){
            count[num]++;
        }
        //return elements that appear more than n/3 times
        for(auto& x : count){
            if(x.second > n/3){
                res.push_back(x.first);
            }
        }
        return res;
    }
};