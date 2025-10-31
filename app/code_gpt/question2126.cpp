/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
vector<vector<int>> maze(N, vector<int>(N));
bool visited[N][N] = {false};

bool canEscape(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 0 || visited[x][y])
        return false;
    if (x == N - 1 && y == N - 1)
        return true;

    visited[x][y] = true;

    if (canEscape(x + 1, y)) return true; // South
    if (canEscape(x, y + 1)) return true; // East
    if (canEscape(x - 1, y)) return true; // North
    if (canEscape(x, y - 1)) return true; // West

    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> maze[i][j];

    if (canEscape(0, 0))
        cout << "\"RUN!\"\n";
    else
        cout << "\"Welcome to the Upside Down.\"\n";

    return 0;
}
