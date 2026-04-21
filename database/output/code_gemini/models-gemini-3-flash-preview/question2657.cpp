/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N_refens, R, C;
int grid[1005][1005];
int min_p[1005][1005];
map<int, vector<pair<int, int>>> portals;
int max_liars = -1;
bool reached = false;

void dfs(int r, int c, int used) {
    if (reached || used > max_liars || used >= min_p[r][c]) return;
    min_p[r][c] = used;
    if (r == R - 1 && c == C - 1) {
        reached = true;
        return;
    }

    static const int dr[] = {0, 0, 1, -1};
    static const int dc[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != 0) {
            dfs(nr, nc, used);
            if (reached) return;
        }
    }

    int val = grid[r][c];
    if (val > 1) {
        if (portals.count(val)) {
            const auto& p_vec = portals[val];
            for (const auto& p : p_vec) {
                if (p.first != r || p.second != c) {
                    dfs(p.first, p.second, used + 1);
                    if (reached) return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N_refens)) return 0;
    vector<int> freq(N_refens + 1, 0);
    for (int i = 0; i < N_refens; i++) {
        int val;
        cin >> val;
        if (val >= 0 && val <= N_refens) freq[val]++;
    }

    int consistent_v = -1;
    for (int v = 1; v <= N_refens; v++) {
        if (freq[v] == v) {
            consistent_v = v;
            break;
        }
    }

    if (consistent_v == -1) {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    } else {
        cout << "Vamos nessa, temos que sair rapido..." << endl;
        max_liars = N_refens - consistent_v;

        if (!(cin >> R >> C)) return 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
                min_p[i][j] = 1e9;
                if (grid[i][j] > 1) {
                    portals[grid[i][j]].push_back({i, j});
                }
            }
        }

        if (R > 0 && C > 0 && grid[0][0] != 0) {
            dfs(0, 0, 0);
        }

        if (reached) {
            cout << "Tudo nosso" << endl;
        } else {
            cout << "Continuem cavando!" << endl;
        }
    }

    return 0;
}