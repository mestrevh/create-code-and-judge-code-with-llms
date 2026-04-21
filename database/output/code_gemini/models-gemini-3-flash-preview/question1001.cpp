/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Ship {
    int r, c;
    bool alive;
};

void printGrid(int N, int M, const vector<Ship>& ships) {
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < (int)ships.size(); ++i) {
        if (ships[i].alive) {
            grid[ships[i].r][ships[i].c] = 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << grid[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int K;
    if (!(cin >> K)) return 0;

    vector<Ship> ships(K);
    for (int i = 0; i < K; ++i) {
        cin >> ships[i].r >> ships[i].c;
        ships[i].alive = true;
    }

    printGrid(N, M, ships);

    int H, B;
    if (!(cin >> H >> B)) return 0;

    for (int h = 0; h < H; ++h) {
        vector<vector<bool>> hit(N, vector<bool>(M, false));
        for (int b = 0; b < B; ++b) {
            int br, bc;
            if (!(cin >> br >> bc)) break;
            
            int dr[] = {0, 1, 1, -1, -1};
            int dc[] = {0, 1, -1, -1, 1};
            
            for (int i = 0; i < 5; ++i) {
                int nr = (br + dr[i]) % N;
                if (nr < 0) nr += N;
                int nc = (bc + dc[i]) % M;
                if (nc < 0) nc += M;
                hit[nr][nc] = true;
            }
        }

        for (int i = 0; i < K; ++i) {
            if (ships[i].alive) {
                if (hit[ships[i].r][ships[i].c]) {
                    ships[i].alive = false;
                }
            }
        }

        for (int i = 0; i < K; ++i) {
            if (ships[i].alive) {
                ships[i].r = (ships[i].r - 1) % N;
                if (ships[i].r < 0) ships[i].r += N;
                ships[i].c = (ships[i].c + 1) % M;
                if (ships[i].c < 0) ships[i].c += M;
            }
        }

        cout << "\n";
        printGrid(N, M, ships);
    }

    return 0;
}