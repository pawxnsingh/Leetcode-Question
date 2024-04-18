class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> highestAltitude(n + 1);

        highestAltitude[0] = 0;

        for (int i = 1; i < highestAltitude.size(); i++) {
            highestAltitude[i] = highestAltitude[i - 1] + gain[i - 1];
        }
        // now find the highest element in this prefix sum array
        int high = highestAltitude[0];
        for (int i = 1; i < highestAltitude.size(); i++) {
            if (highestAltitude[i] >= high) {
                high = highestAltitude[i];
            }
        }
        return high;
    }
};