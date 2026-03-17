class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int x=0; x<n; x++){
            vector<int> arr(n);
            for(int i=0; i<n; i++){
                arr[i] = nums[(i+x) % n];
            }
            bool isSorted = true;
            for(int i=0; i<n-1; i++){
                if(arr[i] > arr[i+1]){
                    isSorted = false;
                    break;
                }
            }
            if(isSorted)    return true;
        }
        return false;
    }
};