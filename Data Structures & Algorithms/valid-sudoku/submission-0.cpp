class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool squares[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rows[i][board[i][j] - '1'] || cols[j][board[i][j] - '1'] 
                    || squares[(i / 3) + (3 * (j / 3))][board[i][j] - '1']) {
                        return false;
                    }
                    rows[i][board[i][j] - '1'] = true;
                    cols[j][board[i][j] - '1'] = true;
                    squares[(i / 3) + (3 * (j / 3))][board[i][j] - '1'] = true;
                }
                
            }
        }

        return true;
    }
};
