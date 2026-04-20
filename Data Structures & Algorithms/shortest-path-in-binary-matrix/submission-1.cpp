class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] || grid[grid.size() - 1][grid[0].size() - 1]) {
            return -1;
        }
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX - 1));
        dp[0][0] = 1;

        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                if (!grid[i][j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
                    if (i > 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    if (j > 0) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }

        if (dp[grid.size() - 1][grid[0].size() - 1] == INT_MAX - 1) {
            return -1;
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};