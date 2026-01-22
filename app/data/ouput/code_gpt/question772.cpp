/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Move {
    int x, y;
};

const int DX[] = {-1, 0, 1, 0, -1, 1};
const int DY[] = {0, -1, 0, 1, -1, 1};
int N, M, area;
char grid[50][50];
bool visited[50][50];

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y <= x; // Trapezoidal bounds
}

void bfs(int startX, int startY, char player) {
    queue<Move> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    area = 0;

    while (!q.empty()) {
        Move curr = q.front();
        q.pop();
        area++;

        for (int i = 0; i < 6; i++) {
            int nx = curr.x + DX[i];
            int ny = curr.y + DY[i];
            if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == player) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

bool checkWin(char player) {
    if (player == 'B') {
        for (int i = 0; i < N; i++) {
            if (grid[i][0] == 'B' && !visited[i][0]) {
                bfs(i, 0, 'B');
                if (visited[i][N - 1]) return true;
            }
        }
    } else {
        for (int j = 0; j < N; j++) {
            if (grid[0][j] == 'W' && !visited[0][j]) {
                bfs(0, j, 'W');
                if (visited[N - 1][j]) return true;
            }
        }
    }
    return false;
}

int main() {
    int K;
    cin >> K;

    for (int c = 0; c < K; c++) {
        cin >> N;
        char starter;
        cin >> starter;
        memset(grid, 0, sizeof(grid));
        memset(visited, 0, sizeof(visited));
        
        vector<pair<int, int>> moves;
        
        while (true) {
            int r, c;
            cin >> r;
            if (cin.eof() || r == -1) break; // Handle input gracefully
            cin >> c;
            moves.push_back({r, c});
            grid[r][c] = (moves.size() % 2 == (starter == 'B' ? 0 : 1)) ? 'B' : 'W';
        }
        
        bool winner = false;
        if (checkWin('B')) {
            cout << "caso " << c << ": B " << area << endl;
            winner = true;
        }

        if (!winner && checkWin('W')) {
            cout << "caso " << c << ": W " << area << endl;
        }

        cout << endl;
    }
    return 0;
}
