class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums){
        int n = nums.size();

        int i = 0;
        while(i<n)
        {
            if(nums[i] != i+1)
            {
                int correctIdx = nums[i] - 1;
                if(nums[i] != nums[correctIdx])
                {
                    swap(nums[i],nums[correctIdx]);
                }
                else
                {
                    i++;
                }
            }
            else 
                i++;
        }
        
        vector<int>dup;
        for(int i=0;i<n;i++)
        {
            if(nums[i] != i+1)
            {
                dup.push_back(nums[i]);
            }
        }
        return dup;
    }
};