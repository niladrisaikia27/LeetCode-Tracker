class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        // Condition 1: First element must be 1
        arr[0] = 1;
        // Condition 2: Maximize each subsequent element based on the previous one
        for (int i = 1; i < arr.size(); ++i) {
            if(arr[i] > arr[i-1] + 1){
                arr[i] = arr[i-1] + 1;
            }
        }
        // The last element will hold the maximum possible value
        return arr.back();
    }
};