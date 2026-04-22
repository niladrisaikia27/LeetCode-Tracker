class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        // Iterate through each word in the queries array
        for (const string& q : queries) {
            // Check the current query against each word in the dictionary
            for (const string& d : dictionary) {
                int diffCount = 0;
                
                // Compare characters at each position
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        diffCount++;
                    }
                }
                
                // If the number of differences is 2 or less, it's a valid match
                if (diffCount <= 2) {
                    result.push_back(q);
                    break; // Move to the next query since we found a valid dictionary word
                }
            }
        }
        
        return result;
    }
};