/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        if (n < 0 || m < 0) break;
        
        vector<vector<char>> grid(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> grid[i][j];
            }
        }

        int t;
        if (!(cin >> t)) break;
        while (t--) {
            int x, y, l;
            string s;
            cin >> x >> y >> s >> l;

            long long cost = 0;
            if (s == "cima") {
                for (int i = x - 1; i >= 1; --i) {
                    if (grid[i][y] == '#') cost += 2;
                    else if (grid[i][y] == '%') cost += 3;
                }
            } else if (s == "baixo") {
                for (int i = x + 1; i <= n; ++i) {
                    if (grid[i][y] == '#') cost += 2;
                    else if (grid[i][y] == '%') cost += 3;
                }
            } else if (s == "esquerda") {
                for (int j = y - 1; j >= 1; --j) {
                    if (grid[x][j] == '#') cost += 2;
                    else if (grid[x][j] == '%') cost += 3;
                }
            } else if (s == "direita") {
                for (int j = y + 1; j <= m; ++j) {
                    if (grid[x][j] == '#') cost += 2;
                    else if (grid[x][j] == '%') cost += 3;
                }
            }

            if (l >= cost) {
                cout << "O amor está no ar!\n";
            } else {
                cout << "Vou voltar pra Limoeiro...\n";
            }
        }
    }

    return 0;
}

