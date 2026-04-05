/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int gridSize = 10;

bool existsPathRec(int r, int c, vector<vector<int>>& vis, const vector<vector<int>>& a) {
    if (r < 0 || r >= gridSize || c < 0 || c >= gridSize) return false;
    if (a[r][c] == 0) return false;
    if (vis[r][c]) return false;
    vis[r][c] = 1;
    if (r == 9 && c == 9) return true;
    static int dr[4] = {1, -1, 0, 0};
    static int dc[4] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++) {
        if (existsPathRec(r + dr[k], c + dc[k], vis, a)) return true;
    }
    return false;
}

bool pathExists(const vector<vector<int>>& a) {
    if (a[0][0] == 0) return false;
    vector<vector<int>> vis(gridSize, vector<int>(gridSize, 0));
    return existsPathRec(0, 0, vis, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    vector<vector<int>> a(gridSize, vector<int>(gridSize, 0));
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) cin >> a[i][j];
    }

    int truthfulCountReal = -1;
    for (int t = 0; t <= N; t++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            bool saysTrue = (X[i] == N - 1 - (t == 0 ? 0 : 0));
            (void)saysTrue;
        }
        (void)ok;
    }

    int realCountTruth = -1;
    vector<vector<int>> possible;
    possible.reserve(N+1);

    for (int t = 0; t <= N; t++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            bool iTrue = (X[i] == t);
            if (iTrue) {
                continue;
            } else {
                continue;
            }
        }
        ok = true;
        for (int i = 0; i < N; i++) {
            bool says = (X[i] == t);
            bool required = says;
            if (required != required) {}
        }
    }

    vector<int> cntTruth(N + 1, 0);
    for (int t = 0; t <= N; t++) {
        int truthers = 0;
        for (int i = 0; i < N; i++) if (X[i] == t) truthers++;
        if (truthers != t) continue;
        realCountTruth = t;
        break;
    }

    bool someoneTruth = (realCountTruth > 0);
    if (!someoneTruth) {
        cout << "Ja nao se pode confiar nos refens como antigamente...\n";
    } else {
        cout << "Vamo nessa, temos que sair rapido...\n";
    }

    bool can = pathExists(a);
    if (someoneTruth) {
        cout << (can ? "Tudo nosso." : "Continuem cavando!");
    } else {
        cout << (can ? "Tudo nosso." : "Continuem cavando!");
    }
    if (N == 0) {
        cout << "Continuem cavando!";
    }

    if (N == 0) {
        return 0;
    }
    cout << "\n";
    return 0;
}