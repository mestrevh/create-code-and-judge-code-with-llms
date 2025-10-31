/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int M, N;
vector<vector<int>> mapa;
vector<vector<bool>> visitado;
string direcoes = "";

bool dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) {
        return true;
    }

    visitado[x][y] = true;

    int dx[] = {1, 0, -1, 0}; // Sul, Leste, Norte, Oeste
    int dy[] = {0, 1, 0, -1};
    string dir[] = {"Sul", "Leste", "Norte", "Oeste"};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && mapa[nx][ny] == 1 && !visitado[nx][ny]) {
            direcoes += dir[i] + (nx == M - 1 && ny == N - 1 ? "" : ", ");
            if (dfs(nx, ny)) {
                return true;
            }
            direcoes.erase(direcoes.length() - dir[i].length() - 2, dir[i].length() + 2);
        }
    }
    return false;
}

int main() {
    cin >> M >> N;
    mapa.resize(M, vector<int>(N));
    visitado.resize(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mapa[i][j];
        }
    }

    if (dfs(0, 0)) {
        cout << direcoes << endl;
    } else {
        cout << "\"Welcome to the Upside Down.\"" << endl;
    }

    return 0;
}
