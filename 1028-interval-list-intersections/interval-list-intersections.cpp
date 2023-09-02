class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>intersectedList;
        if(firstList.size() == 0 || secondList.size() == 0)
        {
            return intersectedList;
        }

        int i = 0;
        int j = 0;
        while(i<firstList.size() && j<secondList.size())
        {
            int maxi = max(firstList[i][0],secondList[j][0]);
            int mini = min(firstList[i][1],secondList[j][1]);

            if(maxi <= mini)
            {
                intersectedList.push_back({maxi,mini});
            }
            if(firstList[i][1] < secondList[j][1])
                i++;
            else 
                j++;
        }
        return intersectedList;
    }
};