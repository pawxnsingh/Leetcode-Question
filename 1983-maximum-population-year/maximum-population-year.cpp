class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // this will iterate through to all the person <P>
        vector<int> arr(101, 0);
        for (int i = 0; i < logs.size(); i++) {
            // the second loop is for the iterate through birthand death ranges
            for (int j = logs[i][0]; j < logs[i][1]; j++) {
                arr[j - 1950]++;
            }
        }
        int maxPop = 0;
        int maxYear = 1950;
        for (int i = 0; i < 101; i++) {
            if (arr[i] > maxPop) {
                maxPop = arr[i];
                maxYear = i + 1950;
            }
        }
        return maxYear;
    }
};