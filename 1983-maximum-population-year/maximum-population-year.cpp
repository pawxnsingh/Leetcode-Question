class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // create an array of 2055 size as per the constaint
        vector<int> v(2051, 0);

        // traverse through the array mark the starting index +1
        // and ending index with -1
        for (auto it : logs) {
            v[it[0]]++;
            v[it[1]]--;
        }

        int max = 0, year = 0;
        // calculate the prefix sum of the array
        for (int i = 1; i < 2051; i++) {
            v[i] += v[i - 1];
            if (max < v[i]) {
                max = v[i];   
                year = i;
            }
        }
        return year;
    }
};