class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(merged.empty() || merged.back()[1] < intervals[i][0])
            {
                merged.push_back({start,end});
            }
            // else if(merged.back()[1] >= intervals[i][0])
            else
            {
                merged.back()[1] = max(merged.back()[1],intervals[i][1]);
            }
        }
        return merged;
    }
};