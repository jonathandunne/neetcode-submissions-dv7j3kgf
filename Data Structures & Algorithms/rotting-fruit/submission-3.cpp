class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> bfs;
        int time = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    bfs.push({i, j});
                }
            }
        }


        while (!bfs.empty()) {
            bool found = false;
            int bfsSize = bfs.size();
            for (int i = 0; i < bfsSize; i++) {
                pair<int, int> top = bfs.front();
                bfs.pop();
                grid[top.first][top.second] = 2;
                if (top.first > 0 && grid[top.first - 1][top.second] == 1) {
                    bfs.push({top.first - 1, top.second});
                    grid[top.first - 1][top.second] = 2;
                    found = true;
                }
                if (top.second > 0 && grid[top.first][top.second - 1] == 1) {
                    bfs.push({top.first, top.second - 1});
                    grid[top.first][top.second - 1] = 2;
                    found = true;
                }
                if (top.first < grid.size() - 1 && grid[top.first + 1][top.second] == 1) {
                    bfs.push({top.first + 1, top.second});
                    grid[top.first + 1][top.second] = 2;
                    found = true;
                }
                if (top.second < grid[0].size() - 1 && grid[top.first][top.second + 1] == 1) {
                    bfs.push({top.first, top.second + 1});
                    grid[top.first][top.second + 1] = 2;
                    found = true;
                }
            }
            if (found) {
                time++;
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
