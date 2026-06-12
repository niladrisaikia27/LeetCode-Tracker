class Solution {
private:
    void recursivePermute(int index, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        if(index == n){
            ans.push_back(nums);
            return;
        }
        set<int> freq;
        for(int i=index; i<n; i++){
            if(freq.count(nums[i])){ 
                continue;
            }
            freq.insert(nums[i]);

            swap(nums[index], nums[i]);
            recursivePermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recursivePermute(0, nums, ans);
        return ans;
    }
};