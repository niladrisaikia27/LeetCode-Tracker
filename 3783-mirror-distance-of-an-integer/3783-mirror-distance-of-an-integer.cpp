class Solution {
public:
    int mirrorDistance(int n) {
        long long original = n;
        long long reversed = 0;
        long long temp = n;

        // Extract digits one by one and build the reversed number
        while (temp > 0) {
            reversed = (reversed * 10) + (temp % 10);
            temp /= 10;
        }

        // Calculate the absolute difference
        // Using std::abs and casting the result back to int
        long long diff = original - reversed;
        return (diff < 0) ? -diff : diff;
    }
};