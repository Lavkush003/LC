class Solution {
public:
    bool check(int row, int col, vector<string>& board, int n) {
        int i, j;

        i = row - 1;
        j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        j = col - 1;
        while (j >= 0) {
            if (board[row][j] == 'Q')
                return false;
            j--;
        }

        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }

        return true;
    }

    void NQueen(vector<vector<string>>& res, int col, vector<string>& board, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (check(row, col, board, n)) {
                board[row][col] = 'Q';
                NQueen(res, col + 1, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board(n, s);
        int col = 0;

        NQueen(res, col, board, n);

        return res;
    }
};