class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (int num : nums) {
            int candidate = 1;
            if (numSet.find(num - 1) != numSet.end()) {
                continue;
            }
            while (numSet.find(num + 1) != numSet.end()) {
                candidate++;
                num++;
            }

            longest = max(longest, candidate);
        }


        return longest;
    }
};
