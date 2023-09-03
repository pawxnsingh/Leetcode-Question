class Solution {
public:
    void insertInterval(vector<vector<int>>&intervals,vector<int>newInterval)
    {
        bool isIntervalInserted = false;
        for(int i=0;i<intervals.size();i++)
        {
            if(newInterval[0] < intervals[i][0])
            {
                intervals.insert(intervals.begin()+i,newInterval);
                isIntervalInserted = true;
                break;
            }

        }
        if(!isIntervalInserted)
        {
            intervals.push_back(newInterval);
        }
    }



    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        // we can break this Question into Part 
        // first one is insert the newinterval in the intervals
        // then after inserting the newinterval we can just check if they overlap or not
    
        // step1 -> insert the newInterval in Between
        insertInterval(intervals,newInterval);
        // step2 -> now interval is Inserted now we have to chceck for overlapping interval
        vector<vector<int>>answer;
        for(int i=0;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(answer.empty() || answer.back()[1] < intervals[i][0])
            {
                answer.push_back({start,end});
            }
            else{
                answer.back()[1] = max(answer.back()[1],intervals[i][1]);
            }
        }
        return answer;
    }
};