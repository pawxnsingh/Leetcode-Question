class Solution {
public:
    int missingNumber(vector<int>& nums){
        int n = nums.size();

        int i = 0;
        while(i<nums.size())
        {
            while(nums[i] < n && nums[i] != i)
            {
                swap(nums[i],nums[nums[i]]);
            }

            i++;
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
                return i;
        }
        return n;
    }
};