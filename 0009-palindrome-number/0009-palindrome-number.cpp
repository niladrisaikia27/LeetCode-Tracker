class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
        int sum =0;
        if(x < 0)
            return false;
        while(dup!=0){
            int last = dup % 10;
            dup = dup /10;

            if(sum > INT_MAX/10 || sum == INT_MAX/10 && last > 7)
                return 0;
            //if(sum < INT_MIN/10 || sum == INT_MIN/10 && last < -8)
              //  return 0;

            sum = (sum*10) + last ;
        }
        if(sum == x)
            return 1;
        else    return 0;
    }
};