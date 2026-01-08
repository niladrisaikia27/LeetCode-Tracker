class Solution {
public:
    int reverse(int x) {
        int sum =0;
        while(x!=0){
            int last = x % 10;
            x = x / 10;

            if(sum > INT_MAX/10 || sum == INT_MAX/10 && last > 7)
                return 0;
            if(sum < INT_MIN/10 || sum == INT_MIN && last < -8)
                return 0;

            sum = (sum * 10) + last;
        }
        return sum;
    }
};