class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num1_copy(nums1.begin(), nums1.begin()+m);

        int p1=0, p2=0;
        for(int i=0; i<m+n; i++){
            if(p2>=n || (p1<m && num1_copy[p1] < nums2[p2])){
                nums1[i] = num1_copy[p1];
                p1++;
            }
            else{
                nums1[i] = nums2[p2];
                p2++;
            }
        }
    }
};