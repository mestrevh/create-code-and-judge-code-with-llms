/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<string> path;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
string names[] = {"Sul", "Leste", "Norte", "Oeste"};

bool solve(int r, int c) {
    if (r == M - 1 && c == N - 1) {
        return true;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < M && nc >= 0 && nc < N && grid[nr][nc] == 1 && !visited[nr][nc]) {
            path.push_back(names[i]);
            if (solve(nr, nc)) return true;
            path.pop_back();
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> M >> N)) return 0;
    if (M <= 0 || N <= 0) return 0;

    grid.assign(M, vector<int>(N));
    visited.assign(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!(cin >> grid[i][j])) break;
        }
    }

    if (grid[0][0] == 1 && solve(0, 0)) {
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i == path.size() - 1 ? "" : ", ");
        }
        cout << endl;
    } else {
        cout << "Welcome to the Upside Down." << endl;
    }

    return 0;
}