class Solution {
public:
    vector<vector<int>> recurse(vector<int>& tree, vector<int>& nums, int target, int index) {
        if (target < 0) {
            return {};
        }
        else if (target == 0) {
            return {tree};
        }

        vector<vector<int>> combinations;

        for (int i = index; i < nums.size(); i++) {
            vector<int> temp = tree;
            temp.push_back(nums[i]);
            vector<vector<int>> valid = recurse(temp, nums, target - nums[i], i);
            combinations.insert(combinations.end(), valid.begin(), valid.end());
        }

        return combinations;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combinations;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp = {nums[i]};
            vector<vector<int>> valid = recurse(temp, nums, target - nums[i], i);
            combinations.insert(combinations.end(), valid.begin(), valid.end());
        }

        return combinations;
    }
};
