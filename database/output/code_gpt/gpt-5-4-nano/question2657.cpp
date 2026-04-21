/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string buildTruthPrefix(int N, const vector<int>& X) {
    int sum = 0;
    for (int v : X) sum += v;
    if (sum >= N) return "Vamo nessa, temos que sair rapido...";
    return "Ja nao se pode confiar nos refens como antigamente...";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    string firstLine = buildTruthPrefix(N, X);

    vector<pair<int,int>> portalsPos; 
    vector<int> portalId;
    vector<vector<int>> portalIndex(n, vector<int>(m, -1));
    unordered_map<int, vector<int>> tmp; 
    tmp.reserve(n*m*2);

    int portalCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v = a[i][j];
            if (v > 1) {
                int id = v;
                if (!tmp.count(id)) tmp[id] = {};
                portalIndex[i][j] = (int)portalCount;
                portalsPos.push_back({i,j});
                portalId.push_back(id);
                portalCount++;
                tmp[id].push_back(portalIndex[i][j]);
            }
        }
    }

    int maxMent = N;
    int destR = n - 1, destC = m - 1;

    vector<vector<vector<char>>> vis(n, vector<vector<char>>(m, vector<char>(maxMent + 1, 0)));
    function<bool(int,int,int)> dfs = [&](int r, int c, int usedMent) -> bool {
        if (r == destR && c == destC) return true;
        if (vis[r][c][usedMent]) return false;
        vis[r][c][usedMent] = 1;

        static int dr[4] = {-1,1,0,0};
        static int dc[4] = {0,0,-1,1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            int cell = a[nr][nc];
            if (cell == 0) continue;

            int nUsed = usedMent;
            if (cell > 1) nUsed = usedMent + 1;
            if (nUsed <= maxMent) {
                if (dfs(nr, nc, nUsed)) return true;
            }
            if (cell > 1) {
                int id = cell;
                if (usedMent <= maxMent) {
                    auto it = tmp.find(id);
                    if (it != tmp.end()) {
                        for (int idx : it->second) {
                            auto [pr, pc] = portalsPos[idx];
                            if (pr == nr && pc == nc) continue;
                            if (dfs(pr, pc, usedMent)) return true;
                        }
                    }
                }
            }
        }

        if (a[r][c] > 1) {
            int id = a[r][c];
            auto it = tmp.find(id);
            if (it != tmp.end()) {
                for (int idx : it->second) {
                    auto [pr, pc] = portalsPos[idx];
                    if (pr == r && pc == c) continue;
                    if (dfs(pr, pc, usedMent)) return true;
                }
            }
        }

        return false;
    };

    bool hasAnyTruth = (accumulate(X.begin(), X.end(), 0) >= N);

    string secondLine;
    if (hasAnyTruth) {
        bool ok = dfs(0, 0, 0);
        secondLine = ok ? "Tudo nosso" : "Continuem cavando!";
        cout << firstLine << "\n" << secondLine << "\n";
    } else {
        cout << firstLine << "\n";
    }

    return 0;
}