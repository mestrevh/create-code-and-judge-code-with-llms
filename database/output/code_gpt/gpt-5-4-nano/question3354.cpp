/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        string line;
        grid[i].reserve(2 * m);
        for (int j = 0; j < m; j++) {
            string tok;
            cin >> tok;
            grid[i].push_back(tok.empty() ? '#' : tok[0]);
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int x, y;
        string S;
        long long L;
        cin >> x >> y;
        cin >> S;
        cin >> L;

        int dx = 0, dy = 0;
        if (S == "direita") { dx = 0; dy = 1; }
        else if (S == "esquerda") { dx = 0; dy = -1; }
        else if (S == "cima") { dx = -1; dy = 0; }
        else if (S == "baixo") { dx = 1; dy = 0; }

        int cx = x - 1;
        int cy = y - 1;

        long long cost = 0;
        bool ok = false;

        while (true) {
            cx += dx;
            cy += dy;
            if (cx < 0 || cx >= n || cy < 0 || cy >= m) {
                ok = true;
                break;
            }
            cost += 1;
            if (grid[cx][cy] == '%') cost += 1;
            if (cost > L) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "O amor está no ar!\n";
        else cout << "Vou voltar pra Limoeiro...\n";
    }

    return 0;
}