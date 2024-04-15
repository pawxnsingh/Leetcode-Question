class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodCount = 0;
        // here maintain the frequency array
        int freqArr[101] = {0};
        for(int i=0;i<nums.size();i++){
            goodCount += freqArr[nums[i]]++;
        }
        return goodCount;
    }
};