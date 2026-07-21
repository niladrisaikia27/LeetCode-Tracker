class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        //find maximum start in the interval
        int max_val = 0;
        for(const auto& start : intervals){
            max_val = max(max_val, start[0]);
        }

        //create a vector/array to store max end where index represents start and value represents max end reached from that start
        vector<int> max_end(max_val + 1, -1);
        for(const auto& start : intervals){
            max_end[start[0]] = max(max_end[start[0]], start[1]);
        }

        vector<vector<int>> merged;
        int current_start = -1;
        int current_end = -1;

        //loop through max_end , update the result and insert it into merged
        for(int i=0; i<=max_val; i++){
            if(max_end[i] == -1)    continue;

            //if it is the starting index
            if(current_start == -1){
                current_start = i;
                current_end = max_end[i];
            }

            else if(i <= current_end){
                current_end = max(current_end, max_end[i]);
            }

            else{
                merged.push_back({current_start, current_end});
                current_start = i;
                current_end = max_end[i];
            }
        }

        if(current_start != -1){
            merged.push_back({current_start, current_end});
        }

        return merged;
    }
};