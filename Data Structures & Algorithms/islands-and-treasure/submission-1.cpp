class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int distance) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || distance >= grid[i][j]) {
            return;
        }
        grid[i][j] = distance;
        dfs(i, j - 1, grid, distance + 1);
        dfs(i, j + 1, grid, distance + 1);
        dfs(i - 1, j, grid, distance + 1);
        dfs(i + 1, j, grid, distance + 1);

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j - 1, grid, 1);
                    dfs(i, j + 1, grid, 1);
                    dfs(i - 1, j, grid, 1);
                    dfs(i + 1, j, grid, 1);
                }
            }
        }
    }
};
