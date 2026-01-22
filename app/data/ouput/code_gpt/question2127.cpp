/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 10;
vector<vector<int>> grid(N, vector<int>(N));
bool visited[N][N];

bool canEscape(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N || grid[x][y] == 0 || visited[x][y])
        return false;
    if (x == N - 1 && y == N - 1) return true;
    
    visited[x][y] = true;

    if (canEscape(x + 1, y) || canEscape(x - 1, y) || canEscape(x, y + 1) || canEscape(x, y - 1))
        return true;

    visited[x][y] = false;
    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    if (canEscape(0, 0)) 
        cout << "\"RUN!\"" << endl;
    else 
        cout << "\"Welcome to the Upside Down.\"" << endl;

    return 0;
}
