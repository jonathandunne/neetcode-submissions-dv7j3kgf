class Solution {
public:
    int islandSize(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || !grid[i][j]) {
            return 0;
        }
        grid[i][j] = 0;

        return 1 + islandSize(i + 1, j, grid) + islandSize(i - 1, j, grid)
         + islandSize(i, j + 1, grid) + islandSize(i, j - 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, islandSize(i, j, grid));
                }
            }
        }



        return maxArea;
    }
};
