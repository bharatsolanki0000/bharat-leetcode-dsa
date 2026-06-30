class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool dfs(vector<vector<char>>& board, string &word, int row, int col, int index) {

        if (index == word.size())
            return true;

        char temp = board[row][col];
        board[row][col] = '#';

        int m = board.size();
        int n = board[0].size();

        for (int k = 0; k < 4; k++) {
            int x = row + dx[k];
            int y = col + dy[k];

            if (x >= 0 && y >= 0 && x < m && y < n &&
                board[x][y] == word[index]) {

                if (dfs(board, word, x, y, index + 1)) {
                    board[row][col] = temp;
                    return true;
                }
            }
        }

        board[row][col] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 1))
                        return true;
                }
            }
        }

        return false;
    }
};