/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<vector<char>> tabuleiro;
set<pair<int, int>> disparos;

void dfs(int x, int y, vector<vector<bool>>& visitado) {
    if (x < 0 || x >= n || y < 0 || y >= m || tabuleiro[x][y] == '.' || visitado[x][y]) return;
    visitado[x][y] = true;
    dfs(x + 1, y, visitado);
    dfs(x - 1, y, visitado);
    dfs(x, y + 1, visitado);
    dfs(x, y - 1, visitado);
}

int main() {
    cin >> n >> m;
    tabuleiro.resize(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> tabuleiro[i][j];
    
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int l, c;
        cin >> l >> c;
        disparos.insert({l - 1, c - 1});
    }

    vector<vector<bool>> visitado(n, vector<bool>(m, false));
    int naviosDestruidos = 0;

    for (auto& disparo : disparos) {
        int x = disparo.first, y = disparo.second;
        if (tabuleiro[x][y] == '#') {
            tabuleiro[x][y] = '.';
            dfs(x, y, visitado);
            naviosDestruidos++;
            while (true) {
                bool shipFound = false;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (tabuleiro[i][j] == '#' && !visitado[i][j]) {
                            dfs(i, j, visitado);
                            shipFound = true;
                        }
                    }
                }
                if (!shipFound) break;
                naviosDestruidos++;
            }
        }
    }

    cout << naviosDestruidos << endl;
    return 0;
}
