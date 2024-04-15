class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            int search = target - nums[i];
            if (hash.find(search) != hash.end()) {
                temp.push_back(i);
                temp.push_back(hash[search]);
                break;
            }
            hash[nums[i]] = i;
        }
        return temp;
    }
};