class Solution {
public:
    bool dfsPacific(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& canReachPacific) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[i].size() || canReachPacific[i][j] == 2) {
            return false;
        }
        if (canReachPacific[i][j] == 1 || i == 0 || j == 0) {
            return true;
        }

        canReachPacific[i][j] = 3;

        bool output = false;
        if (i < heights.size() - 1 && heights[i + 1][j] <= heights[i][j] && canReachPacific[i + 1][j] != 3) {
            output = output || dfsPacific(i + 1, j, heights, canReachPacific);
        }
        if (i > 0 && heights[i - 1][j] <= heights[i][j] && canReachPacific[i - 1][j] != 3) {
            output = output || dfsPacific(i - 1, j, heights, canReachPacific);
        }
        if (j < heights[0].size() - 1 && heights[i][j + 1] <= heights[i][j] && canReachPacific[i][j + 1] != 3) {
            output = output || dfsPacific(i, j + 1, heights, canReachPacific);
        }
        if (j > 0 && heights[i][j - 1] <= heights[i][j] && canReachPacific[i][j - 1] != 3) {
            output = output || dfsPacific(i, j - 1, heights, canReachPacific);
        }
        
        if (output) {
            canReachPacific[i][j] = 1;
            return true;
        }
        else {
            canReachPacific[i][j] = 2;
            return false;
        }
    }
    bool dfsAtlantic(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& canReachAtlantic) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[i].size() || canReachAtlantic[i][j] == 2) {
            return false;
        }
        if (canReachAtlantic[i][j] == 1 || i == heights.size() - 1 || j == heights[0].size() - 1) {
            return true;
        }

        canReachAtlantic[i][j] = 3;

        bool output = false;
        if (i < heights.size() - 1 && heights[i + 1][j] <= heights[i][j] && canReachAtlantic[i + 1][j] != 3) {
            output = output || dfsAtlantic(i + 1, j, heights, canReachAtlantic);
        }
        if (i > 0 && heights[i - 1][j] <= heights[i][j] && canReachAtlantic[i - 1][j] != 3) {
            output = output || dfsAtlantic(i - 1, j, heights, canReachAtlantic);
        }
        if (j < heights[0].size() - 1 && heights[i][j + 1] <= heights[i][j] && canReachAtlantic[i][j + 1] != 3) {
            output = output || dfsAtlantic(i, j + 1, heights, canReachAtlantic);
        }
        if (j > 0 && heights[i][j - 1] <= heights[i][j] && canReachAtlantic[i][j - 1] != 3) {
            output = output || dfsAtlantic(i, j - 1, heights, canReachAtlantic);
        }
        
        if (output) {
            canReachAtlantic[i][j] = 1;
            return true;
        }
        else {
            canReachAtlantic[i][j] = 2;
            return false;
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 1 && heights[0].size() == 1) {
            return {{0, 0}};
        }
        vector<vector<int>> output;

        // 0: Not discovered, 1: Able to reach ocean, 2: unable to reach ocean, 3: visited still undecided
        vector<vector<int>> canReachPacific(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> canReachAtlantic(heights.size(), vector<int>(heights[0].size(), 0));

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (dfsPacific(i, j, heights, canReachPacific) && dfsAtlantic(i, j, heights, canReachAtlantic)) {
                    output.push_back({i, j});
                }
            }
        }


        return output;
    }
};
