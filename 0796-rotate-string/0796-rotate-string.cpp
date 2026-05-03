class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        std::string doubleS = s + s;
        return doubleS.find(goal) != std::string::npos;
    }
};