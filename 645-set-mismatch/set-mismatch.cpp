class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while(i<nums.size())
        // [1,2,3,4,7,6,6,5] best test case written by me
        {   
            int correct = nums[i] - 1;
            if(nums[i] != nums[correct])
                swap(nums[i],nums[correct]);
            else
                i++;
        }

        for(int k=0;k<nums.size();k++){
            if(nums[k] != k+1){
                return {nums[k],k+1};
            }
        }
        return {-1,-1};
    }
};