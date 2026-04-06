class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(), 1);
        vector<int> rightProduct(nums.size(), 1);


        // Build left prodcts
        for (int i = 1; i < nums.size(); i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        // Build right prodcts
        for (int i = nums.size() - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }

        // Multiply
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = leftProduct[i] * rightProduct[i];
        }

        return nums;
    }
};
