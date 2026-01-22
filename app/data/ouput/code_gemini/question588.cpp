/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int max_sum;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void solve(int r, int c, int count, int current_sum) {
    if (count == M) {
        max_sum = max(max_sum, current_sum);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (is_valid(nr, nc) && !visited[nr][nc]) {
            visited[nr][nc] = true;
            solve(nr, nc, count + 1, current_sum + grid[nr][nc]);
            visited[nr][nc] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    grid.assign(N, vector<int>(N));
    visited.assign(N, vector<bool>(N, false));
    max_sum = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = true;
            solve(i, j, 1, grid[i][j]);
            visited[i][j] = false;
        }
    }

    cout << max_sum << endl;

    return 0;
}
