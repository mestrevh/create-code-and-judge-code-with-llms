/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;

    auto parseDims = [&](const string& s) -> pair<int,int> {
        int i = 0;
        while (i < (int)s.size() && isspace((unsigned char)s[i])) i++;
        int a = 0;
        while (i < (int)s.size() && isdigit((unsigned char)s[i])) {
            a = a * 10 + (s[i] - '0');
            i++;
        }
        while (i < (int)s.size() && (s[i] == 'x' || s[i] == 'X')) i++;
        int b = 0;
        while (i < (int)s.size() && isdigit((unsigned char)s[i])) {
            b = b * 10 + (s[i] - '0');
            i++;
        }
        return {a, b};
    };

    auto [n, m] = parseDims(line);

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        if (!getline(cin, grid[i])) grid[i] = "";
        while ((int)grid[i].size() < m) {
            string extra;
            if (!getline(cin, extra)) break;
            grid[i] += extra;
        }
    }

    pair<int,int> start = {-1,-1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'o') start = {i, j};
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    if (start.first != -1) {
        dist[start.first][start.second] = 0;
        q.push(start);
    }

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    int best = -1;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        if (grid[r][c] == 'd') {
            best = dist[r][c];
            break;
        }
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    if (best != -1) {
        cout << "Apos correr " << best << " metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n";
    } else {
        cout << "Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n";
    }

    return 0;
}