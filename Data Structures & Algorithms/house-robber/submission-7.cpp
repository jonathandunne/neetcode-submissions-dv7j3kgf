class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int temp;
        int prev = nums[0];
        int curr = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            temp = curr;
            curr = max(curr, nums[i] + prev);
            prev = temp;
        }

        return curr;
    }
};
