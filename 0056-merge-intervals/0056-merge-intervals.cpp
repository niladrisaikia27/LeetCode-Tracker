class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        bool mergedAny = true;

        while(mergedAny){
            mergedAny = false;
            for(int i=0; i<intervals.size(); i++){
                for(int j=i+1; j<intervals.size(); j++){
                    //check if first element of j is smaller than second element of i
                    if(max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1])){
                        //merge the intervals into i
                        intervals[i][0] = min(intervals[i][0], intervals[j][0]);
                        intervals[i][1] = max(intervals[i][1], intervals[j][1]);

                        //delete the j interval
                        intervals.erase(intervals.begin() + j);
                        mergedAny =  true;
                        break;                  
                    }
                }
                if(mergedAny)   break;
            }
        }
        return intervals;
    }
};