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
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    int maxSum = INT_MIN;

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    auto inside = [&](int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N;
    };

    function<void(int,int)> addCandidate = [&](int r, int c) {};

    for (int si = 0; si < N; si++) {
        for (int sj = 0; sj < N; sj++) {
            vector<int> compIndex(N * N, -1);
            vector<pair<int,int>> cells;
            queue<pair<int,int>> q;
            compIndex[si * N + sj] = 0;
            q.push({si, sj});
            cells.push_back({si, sj});

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (!inside(nr, nc)) continue;
                    int id = nr * N + nc;
                    if (compIndex[id] != -1) continue;
                    compIndex[id] = 0;
                    q.push({nr, nc});
                    cells.push_back({nr, nc});
                }
            }
        }
    }

    vector<vector<char>> visited(N, vector<char>(N, 0));
    vector<pair<int,int>> chosen;
    chosen.reserve(M);

    long long totalNodes = (long long)N * N;

    struct Frame {
        int r, c;
        vector<pair<int,int>> neigh;
    };

    vector<pair<int,int>> frontier;
    vector<pair<int,int>> frontier2;

    function<void(int,int,int,long long)> dfs;
    dfs = [&](int startR, int startC, int k, long long sum) {
        if (k == M) {
            if (sum > maxSum) maxSum = (int)sum;
            return;
        }
        if ((int)frontier.size() + k < M) return;

        long long bestAdd = 0;
        int need = M - k;
        vector<int> vals;
        vals.reserve(frontier.size());
        for (auto &p : frontier) vals.push_back(a[p.first][p.second]);
        nth_element(vals.begin(), vals.begin() + min(need-1, (int)vals.size()-1), vals.end(), greater<int>());
        if ((int)vals.size() >= need) {
            vector<int> tmp = vals;
            sort(tmp.begin(), tmp.end(), greater<int>());
            bestAdd = 0;
            for (int i = 0; i < need; i++) bestAdd += tmp[i];
            if (sum + bestAdd <= maxSum) return;
        }

        for (int i = 0; i < (int)frontier.size(); i++) {
            auto [r, c] = frontier[i];
            if (visited[r][c]) continue;

            visited[r][c] = 1;
            chosen.push_back({r, c});

            frontier2.clear();
            for (int j = i + 1; j < (int)frontier.size(); j++) {
                auto p = frontier[j];
                if (!visited[p.first][p.second]) frontier2.push_back(p);
            }

            vector<pair<int,int>> add;
            for (int t = 0; t < 4; t++) {
                int nr = r + dr[t], nc = c + dc[t];
                if (!inside(nr, nc)) continue;
                if (!visited[nr][nc]) add.push_back({nr, nc});
            }

            for (auto &p : add) frontier2.push_back(p);

            frontier.swap(frontier2);

            dfs(startR, startC, k + 1, sum + a[r][c]);

            frontier.swap(frontier2);
            frontier2.clear();

            for (int j = i + 1; j < (int)frontier.size(); j++) {
                auto p = frontier[j];
            }

            chosen.pop_back();
            visited[r][c] = 0;

            frontier.clear();
            frontier.reserve(4 * M + 10);
            for (int j = 0; j < (int)frontier2.size(); j++) {
                (void)j;
            }
        }
    };

    vector<pair<int,int>> allCells;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            allCells.push_back({i, j});

    int maxVal = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            maxVal = max(maxVal, a[i][j]);

    maxSum = INT_MIN;

    vector<int> order(allCells.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y){
        auto [rx, cx] = allCells[x];
        auto [ry, cy] = allCells[y];
        return a[rx][cx] > a[ry][cy];
    });

    int DR[4] = {-1, 1, 0, 0};
    int DC[4] = {0, 0, -1, 1};

    function<void(int,int,int,long long, vector<pair<int,int>>)> search = [&](int r, int c, int k, long long sum, vector<pair<int,int>> fr) {
        if (k == M) {
            if (sum > maxSum) maxSum = (int)sum;
            return;
        }
        if ((int)fr.size() < M - k) return;

        int need = M - k;
        vector<int> vals;
        vals.reserve(fr.size());
        for (auto &p : fr) vals.push_back(a[p.first][p.second]);
        if ((int)vals.size() >= need) {
            sort(vals.begin(), vals.end(), greater<int>());
            long long bound = sum;
            for (int i = 0; i < need; i++) bound += vals[i];
            if (bound <= maxSum) return;
        }

        sort(fr.begin(), fr.end(), [&](auto &p1, auto &p2){
            return a[p1.first][p1.second] > a[p2.first][p2.second];
        });
        for (int i = 0; i < (int)fr.size(); i++) {
            auto [nr, nc] = fr[i];
            if (visited[nr][nc]) continue;

            visited[nr][nc] = 1;
            vector<pair<int,int>> fr2;
            fr2.reserve(fr.size() + 4);

            for (int j = i + 1; j < (int)fr.size(); j++) {
                auto p = fr[j];
                if (!visited[p.first][p.second]) fr2.push_back(p);
            }

            for (int t = 0; t < 4; t++) {
                int ar = nr + DR[t], ac = nc + DC[t];
                if (!inside(ar, ac)) continue;
                if (!visited[ar][ac]) fr2.push_back({ar, ac});
            }

            search(nr, nc, k + 1, sum + a[nr][nc], fr2);
            visited[nr][nc] = 0;

            if (M - (k + 1) == 0) return;
        }
    };

    for (int idx = 0; idx < (int)order.size(); idx++) {
        auto [si, sj] = allCells[order[idx]];
        visited.assign(N, vector<char>(N, 0));
        visited[si][sj] = 1;
        vector<pair<int,int>> fr;
        for (int k = 0; k < 4; k++) {
            int ni = si + DR[k], nj = sj + DC[k];
            if (inside(ni, nj) && !visited[ni][nj]) fr.push_back({ni, nj});
        }
        search(si, sj, 1, a[si][sj], fr);
    }

    cout << maxSum << "\n";
    return 0;
}