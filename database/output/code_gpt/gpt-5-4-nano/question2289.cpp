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

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cin >> grid[i][j];
    }

    int allTruth = 1, anyTruth = 0;
    for (int i = 0; i < N; i++) {
        if (X[i] == 0) allTruth = 0;
        if (X[i] > 0) anyTruth = 1;
    }

    string prefix;
    if (!anyTruth && allTruth) {
        prefix = "Ja nao se pode confiar nos refens como antigamente...";
        return 0;
    }
    if (anyTruth) prefix = "Vamo nessa, temos que sair rapido...";
    else prefix = "Ja nao se pode confiar nos refens como antigamente...";

    cout << prefix << "\n";

    if (!anyTruth) return 0;

    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    auto isInside = [&](int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    };

    struct Step {
        int r, c;
        int dirIndex;
    };

    vector<pair<int,int>> drdc = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<string> dirName = {"Sul","Leste","Norte","Oeste"};

    function<bool(int,int, vector<string>&)> dfs = [&](int r, int c, vector<string>& path) -> bool {
        if (!isInside(r, c)) return false;
        if (grid[r][c] == 0) return false;
        if (vis[r][c]) return false;

        if (r == rows - 1 && c == cols - 1) {
            path.push_back("");
            path.pop_back();
            return true;
        }

        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + drdc[k].first;
            int nc = c + drdc[k].second;
            if (!isInside(nr, nc) || grid[nr][nc] == 0 || vis[nr][nc]) continue;
            if (dfs(nr, nc, path)) {
                path.push_back(dirName[k]);
                return true;
            }
        }

        vis[r][c] = 0;
        return false;
    };

    vector<string> revPath;
    bool ok = dfs(0, 0, revPath);

    if (!ok) {
        cout << "Continuem cavando!\n";
        return 0;
    }

    reverse(revPath.begin(), revPath.end());
    for (size_t i = 0; i < revPath.size(); i++) {
        if (i) cout << ", ";
        cout << revPath[i];
    }
    cout << "\n";
    return 0;
}