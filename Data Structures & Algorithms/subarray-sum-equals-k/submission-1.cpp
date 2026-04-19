class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        for (int num : nums) {
            sum += num;
            count += prefixSums[sum - k];
            prefixSums[sum]++;
        }

        return count;
    }
};