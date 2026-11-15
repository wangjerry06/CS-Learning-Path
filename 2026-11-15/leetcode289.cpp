// game of life
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = (int)board.size();      // 行数
        int n = (int)board[0].size();   // 列数
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        if (di == 0 && dj == 0) continue;
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        if (board[ni][nj] == 1 || board[ni][nj] == 2) live++;
                        // 1 或 2 都代表原本这个位置的是活细胞
                    }
                }
                if (board[i][j] == 1) {
                    board[i][j] = (live < 2 || live > 3) ? 2 : 1;
                    // 如果周围少于两个或者大于三个，原本活的变死，记做 2
                } else {
                    board[i][j] = (live == 3) ? 3 : 0;
                    // 如果周围正好三个，原本死的复活，记做 3
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 1 || board[i][j] == 3) board[i][j] = 1;
                if (board[i][j] == 2 || board[i][j] == 0) board[i][j] = 0;
            }
        }
    }
};

int main() {
    int m = 0, n = 0;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> board(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    Solution s;
    s.gameOfLife(board);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j];
            if (j + 1 < n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
