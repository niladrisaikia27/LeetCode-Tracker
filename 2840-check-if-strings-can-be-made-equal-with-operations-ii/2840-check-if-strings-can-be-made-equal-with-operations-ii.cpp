class Solution {
public:
    bool checkStrings(string s1, string s2) {
        std::vector<int> countEven1(26, 0), countEven2(26, 0);
        std::vector<int> countOdd1(26, 0), countOdd2(26, 0);
        
        int n = s1.length();
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                countEven1[s1[i] - 'a']++;
                countEven2[s2[i] - 'a']++;
            } else {
                countOdd1[s1[i] - 'a']++;
                countOdd2[s2[i] - 'a']++;
            }
        }
        
        // If the character distribution on even positions and 
        // odd positions matches between both strings, they are equivalent.
        return (countEven1 == countEven2) && (countOdd1 == countOdd2);
    }
};