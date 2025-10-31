/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<vector<char>> mat;
bool visited[100][100];

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < M && y < N && !visited[x][y] && (mat[x][y] == '*' || mat[x][y] == 'S'));
}

bool bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (mat[x][y] == 'S') return true;

        for (auto [dx, dy] : {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)}) {
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    return false;
}

int main() {
    cin >> M >> N;
    mat.resize(M, vector<char>(N));
    int startX, startY;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'E') {
                startX = i;
                startY = j;
            }
        }
    }

    if (bfs(startX, startY)) {
        cout << "Esse Yordle é confiável, vamos por esse atalho." << endl;
    } else {
        cout << "Não tem saída, deve ser a LeBlanc tentando me enganar, melhor dar o fora daqui." << endl;
    }

    return 0;
}
