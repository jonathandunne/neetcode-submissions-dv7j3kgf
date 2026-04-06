class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp = nums;

        dp[1] = max(dp[0], dp[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i] + dp[i - 2], dp[i - 1]);
            cerr << "dp[i]: " << dp[i] << " i: " << i << endl;
        }

        return dp[nums.size() - 1];
    }
};
