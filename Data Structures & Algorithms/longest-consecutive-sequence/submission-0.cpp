class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> found;
        int longest = 0;

        for (int num : nums) {
            if (found.find(num - 1) == found.end()) {
                found[num] = 1;
            }
            else {
                found[num] = found[num - 1] + 1;
            }
            longest = max(longest, found[num]);
        }

        return longest;
    }
};
