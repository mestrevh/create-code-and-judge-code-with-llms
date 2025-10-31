/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, Y, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;

void floodFill(int x, int y, int& count) {
    if (x < 1 || x > N || y < 1 || y > M || visited[x][y] || grid[x][y] == 1) return;

    visited[x][y] = true;
    count++;

    floodFill(x + 1, y, count);
    floodFill(x - 1, y, count);
    floodFill(x, y + 1, count);
    floodFill(x, y - 1, count);
}

int main() {
    cin >> N >> M >> X >> Y >> K;
    grid.assign(N + 1, vector<int>(M + 1, 0));
    visited.assign(N + 1, vector<bool>(M + 1, false));

    for (int i = 0; i < K; i++) {
        int A, B;
        cin >> A >> B;
        grid[A][B] = 1;
    }

    int paintedCount = 0;
    floodFill(X, Y, paintedCount);

    cout << paintedCount << endl;
    return 0;
}
