class Solution {
private:
    void recursivePermute(int index, vector<int>& nums, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            recursivePermute(index+1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursivePermute(0, nums, ans);
        return ans;
    }
};