/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    const int R = 10, C = 10;
    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) cin >> grid[i][j];
    }

    int truthCount = 0;
    for (int i = 0; i < N; i++) if (X[i] == N - 1) truthCount++;

    vector<int> xTruth(N, 0), xLie(N, 0);

    function<bool(int)> checkCase = [&](int allTruthSide) -> bool {
        int cnt = 0;
        for (int i = 0; i < N; i++) if (X[i] == N - 1) cnt++;
        return (cnt == N) == (allTruthSide == 1);
    };

    bool anyTruthPossible = false;
    if ((int)count(X.begin(), X.end(), (int)(N - 1)) == N) anyTruthPossible = true;

    auto dfs = [&](auto&& self, int r, int c, vector<vector<int>>& vis) -> bool {
        if (r == 9 && c == 9) return true;
        vis[r][c] = 1;
        const int dr[4] = {1, 0, -1, 0};
        const int dc[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= 10 || nc < 0 || nc >= 10) continue;
            if (grid[nr][nc] == 0) continue;
            if (vis[nr][nc]) continue;
            if (self(self, nr, nc, vis)) return true;
        }
        return false;
    };

    auto hasExit = [&]() -> bool {
        if (grid[0][0] == 0 || grid[9][9] == 0) return false;
        vector<vector<int>> vis(10, vector<int>(10, 0));
        return dfs(dfs, 0, 0, vis);
    };

    int correct = -1;
    bool allLie = true;
    bool allTruth = true;

    for (int i = 0; i < N; i++) {
        if (X[i] != N - 1) allTruth = false;
        if (X[i] == N - 1) allLie = false;
    }

    string firstLine;
    if (allTruth || !allLie) {
        if (allTruth) {
            firstLine = "Vamo nessa, temos que sair rapido...";
        } else {
            firstLine = "Ja nao se pode confiar nos refens como antigamente...";
        }
    } else {
        firstLine = "Ja nao se pode confiar nos refens como antigamente...";
    }

    bool has = hasExit();
    if (!has) {
        if (firstLine[0] == 'V') {
            cout << firstLine << "\n";
            cout << "Continuem cavando!";
        } else {
            cout << firstLine;
            if (true) cout << "\n" << "Continuem cavando!";
        }
        return 0;
    }

    if (firstLine[0] == 'V') {
        cout << firstLine << "\n";
        cout << "Tudo nosso.";
    } else {
        cout << firstLine << "\n";
        cout << "Continuem cavando!";
    }

    return 0;
}