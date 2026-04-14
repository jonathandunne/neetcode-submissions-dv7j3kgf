class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {

                if (nums[i] + nums[left] + nums[right] == 0) {
                    sums.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && left > i + 1 && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return sums;
    }
};
