class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> found;

        for (int i = 0; i < nums.size(); i++) {
            if (found.find(target - nums[i]) != found.end()) {
                return {found[target - nums[i]], i};
            }
            found[nums[i]] = i;
        }


        return {};
    }
};
