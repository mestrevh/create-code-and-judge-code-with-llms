/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int K;
    cin >> K;

    vector<vector<unsigned char>> grid(N, vector<unsigned char>(M, 0));
    set<pair<int,int>> alive;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        if (0 <= x && x < N && 0 <= y && y < M) {
            if (!grid[x][y]) {
                grid[x][y] = 1;
                alive.insert({x, y});
            }
        }
    }

    int H, B;
    cin >> H >> B;

    vector<pair<int,int>> bombs(H * B);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < B; j++) {
            int x, y;
            cin >> x >> y;
            bombs[i * B + j] = {x, y};
        }
    }

    auto wrap = [&](int x, int y) -> pair<int,int> {
        x = (x % N + N) % N;
        y = (y % M + M) % M;
        return {x, y};
    };

    auto moveStep = [&](int x, int y) -> pair<int,int> {
        int nx = x - 1;
        int ny = y + 1;
        if (nx < 0) nx = N - 1;
        if (ny >= M) ny = 0;
        return {nx, ny};
    };

    auto markBombCells = [&](int bx, int by, vector<pair<int,int>>& targets) {
        int x0 = bx, y0 = by;
        pair<int,int> c;
        auto add = [&](int x, int y) {
            c = wrap(x, y);
            targets.push_back(c);
        };
        add(x0, y0);
        add(x0 + 1, y0 + 1);
        add(x0 + 1, y0 - 1);
        add(x0 - 1, y0 - 1);
        add(x0 - 1, y0 + 1);
    };

    auto printGrid = [&]() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << int(grid[i][j]);
                if (j + 1 < M) cout << ' ';
            }
            cout << "\n";
        }
    };

    printGrid();
    if (H >= 1) cout << "\n";

    for (int hour = 0; hour < H; hour++) {
        vector<pair<int,int>> killTargets;
        killTargets.reserve(B * 5);

        for (int j = 0; j < B; j++) {
            auto [bx, by] = bombs[hour * B + j];
            markBombCells(bx, by, killTargets);
        }

        sort(killTargets.begin(), killTargets.end());
        killTargets.erase(unique(killTargets.begin(), killTargets.end()), killTargets.end());

        for (auto &p : killTargets) {
            int x = p.first, y = p.second;
            if (grid[x][y]) {
                grid[x][y] = 0;
                alive.erase(p);
            }
        }

        vector<pair<int,int>> newAlive;
        newAlive.reserve(alive.size());
        vector<vector<unsigned char>> newGrid(N, vector<unsigned char>(M, 0));
        for (auto &p : alive) {
            auto np = moveStep(p.first, p.second);
            newGrid[np.first][np.second] = 1;
        }
        alive.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (newGrid[i][j]) {
                    grid[i][j] = 1;
                    alive.insert({i, j});
                } else {
                    grid[i][j] = 0;
                }
            }
        }

        if (hour + 1 < H) cout << "\n";
        printGrid();
        if (hour + 1 == H - 1) {
            if (H > 0) cout << "\n";
        } else {
            if (hour + 1 < H - 1) cout << "\n";
        }
    }

    return 0;
}