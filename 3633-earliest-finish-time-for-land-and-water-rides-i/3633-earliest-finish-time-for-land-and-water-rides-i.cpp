class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int minLandFinish = INT_MAX;
        for (int i = 0; i < n; i++) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        int minWaterFinish = INT_MAX;
        for (int j = 0; j < m; j++) {
            minWaterFinish = min(minWaterFinish, waterStartTime[j] + waterDuration[j]);
        }
        
        int earliest_overall = INT_MAX;
        
        for (int j = 0; j < m; j++) {
            int finishTime = max(minLandFinish, waterStartTime[j]) + waterDuration[j];
            earliest_overall = min(earliest_overall, finishTime);
        }
        
        for (int i = 0; i < n; i++) {
            int finishTime = max(minWaterFinish, landStartTime[i]) + landDuration[i];
            earliest_overall = min(earliest_overall, finishTime);
        }
        return earliest_overall;
    }
};