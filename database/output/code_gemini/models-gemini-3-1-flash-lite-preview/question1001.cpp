/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void aplicar_bomba(int x, int y, int N, int M, vector<vector<int>>& grid) {
    int dx[] = {0, 1, 1, -1, -1};
    int dy[] = {0, 1, -1, -1, 1};
    for (int i = 0; i < 5; ++i) {
        int nx = (x + dx[i]) % N;
        if (nx < 0) nx += N;
        int ny = (y + dy[i]) % M;
        if (ny < 0) ny += M;
        grid[nx][ny] = 0;
    }
}

void mover_frota(int N, int M, vector<vector<int>>& grid) {
    vector<vector<int>> nova_grid(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 1) {
                int nx = (i - 1) % N;
                if (nx < 0) nx += N;
                int ny = (j + 1) % M;
                if (ny < 0) ny += M;
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    if (nx < 0) {
                        int tx = (N - 1);
                        int ty = (ny + 1) % M;
                        nova_grid[tx][ty] = 1;
                    } else if (nx >= N) {
                        int tx = 0;
                        int ty = (ny - 1) % M;
                        if (ty < 0) ty += M;
                        nova_grid[tx][ty] = 1;
                    }
                } else {
                    nova_grid[nx][ny] = 1;
                }
            }
        }
    }
    grid = nova_grid;
}

void imprimir_grid(int N, int M, const vector<vector<int>>& grid) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << grid[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = 1;
    }

    imprimir_grid(N, M, grid);

    int H, B;
    cin >> H >> B;
    while (H--) {
        vector<pair<int, int>> bombas(B);
        for (int i = 0; i < B; ++i) cin >> bombas[i].first >> bombas[i].second;
        
        mover_frota(N, M, grid);
        for (auto& b : bombas) {
            aplicar_bomba(b.first, b.second, N, M, grid);
        }
        imprimir_grid(N, M, grid);
    }

    return 0;
}