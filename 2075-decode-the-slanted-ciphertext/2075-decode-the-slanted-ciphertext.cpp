class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        // If the string is empty, return early
        if (n == 0 || rows == 0) {
            return "";
        }
        
        int cols = n / rows;
        string originalText;
        originalText.reserve(n); // Pre-allocate memory to avoid multiple reallocations
        
        // Traverse the implicit matrix diagonally
        for (int start_c = 0; start_c < cols; ++start_c) {
            for (int r = 0; r < rows; ++r) {
                int curr_c = start_c + r;
                
                // If the column index exceeds the total columns, the diagonal ends
                if (curr_c < cols) {
                    // Map the 2D coordinate (r, curr_c) to the 1D index
                    originalText += encodedText[r * cols + curr_c];
                } else {
                    break;
                }
            }
        }
        
        // The original string is guaranteed not to have trailing spaces
        while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }
        
        return originalText;
    }
};