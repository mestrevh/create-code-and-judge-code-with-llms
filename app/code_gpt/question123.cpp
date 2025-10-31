/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

class MegaDamas {
public:
    MegaDamas(int n, int m, const vector<int>& board) : n(n), m(m), max_captures(0) {
        this->board = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 0 && (i * m + j) / 2 < board.size()) {
                    this->board[i][j] = board[(i * m + j) / 2];
                }
            }
        }
    }
    
    int solve() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 1) {
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    dfs(i, j, 0, visited);
                }
            }
        }
        return max_captures;
    }

private:
    int n, m, max_captures;
    vector<vector<int>> board;

    void dfs(int x, int y, int captures, vector<vector<bool>> &visited) {
        visited[x][y] = true;
        bool can_move = false;

        for (int d = 0; d < 4; ++d) {
            int nx = x + directions[d][0] * 2;
            int ny = y + directions[d][1] * 2;
            int mx = x + directions[d][0];
            int my = y + directions[d][1];

            if (is_valid(nx, ny) && is_valid(mx, my) && !visited[nx][ny] && board[mx][my] == 2 && board[nx][ny] == 0) {
                board[mx][my] = 0;
                board[x][y] = 0;
                board[nx][ny] = 1;

                dfs(nx, ny, captures + 1, visited);

                board[mx][my] = 2;
                board[x][y] = 1;
                board[nx][ny] = 0;
                can_move = true;
            }
        }

        if (!can_move) max_captures = max(max_captures, captures);
        visited[x][y] = false;
    }

    bool is_valid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && (x + y) % 2 == 0;
    }
};

int main() {
    int n, m;
    while (cin >> n >> m && n && m) {
        vector<int> board((n * m) / 2);
        for (int i = 0; i < (n * m) / 2; i++) {
            cin >> board[i];
        }

        MegaDamas game(n, m, board);
        cout << game.solve() << endl;
    }
    return 0;
}
