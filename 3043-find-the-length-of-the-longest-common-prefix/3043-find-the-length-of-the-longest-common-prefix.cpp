class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }
        
        int maxLen = 0;
        for (int num : arr2) {
            int len = to_string(num).length();
            while (num > 0 && len > maxLen) {
                if (prefixes.count(num)) {
                    maxLen = len;
                    break;                 }
                num /= 10;
                len--;
            }
        }
        return maxLen;
    }
};