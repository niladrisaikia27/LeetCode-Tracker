class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0; // Horizontal displacement
        int y = 0; // Vertical displacement

        for (char move : moves) {
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'L') {
                x--;
            } else if (move == 'R') {
                x++;
            }
        }

        // Return true only if both coordinates are back at zero
        return (x == 0 && y == 0);
    }
};