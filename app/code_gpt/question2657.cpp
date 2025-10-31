/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int tunnels[10][10];
bool visited[10][10];

bool dfs(int x, int y, int portalsRemaining) {
    if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y] || tunnels[x][y] == 0) return false;
    if (x == N - 1 && y == M - 1) return true;
    visited[x][y] = true;

    if (tunnels[x][y] > 1 && portalsRemaining > 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (tunnels[i][j] == tunnels[x][y] && (i != x || j != y)) {
                    if (dfs(i, j, portalsRemaining - 1)) return true;
                }
            }
        }
    }

    bool found = dfs(x + 1, y, portalsRemaining) || dfs(x - 1, y, portalsRemaining) ||
                 dfs(x, y + 1, portalsRemaining) || dfs(x, y - 1, portalsRemaining);
                 
    visited[x][y] = false;
    return found;
}

int main() {
    int refCount;
    cin >> refCount;

    vector<int> truths(refCount);
    bool anyTrue = false;
    
    for (int i = 0; i < refCount; ++i) {
        cin >> truths[i];
        if (truths[i] > 0) anyTrue = true;
    }

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> tunnels[i][j];

    if (anyTrue) {
        cout << "Vamos nessa, temos que sair rapido..." << endl;

        memset(visited, false, sizeof(visited));
        if (dfs(0, 0, refCount)) {
            cout << "Tudo nosso" << endl;
        } else {
            cout << "Continuem cavando!" << endl;
        }
    } else {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}
