class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndexReached = 0;

        if(nums.size() == 1){
            return true;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (i > maxIndexReached) {
                return false;
            }

            // // how far i can go
            // if (maxIndexReached < i + nums[i]) {
            //     maxIndexReached = i + nums[i];
            // }

            maxIndexReached = max(i + nums[i],maxIndexReached);
        }

        return maxIndexReached >= nums.size() - 1;
    }
};