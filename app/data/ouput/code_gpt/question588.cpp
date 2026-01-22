/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfsMaxTrees(const vector<vector<int>>& farm, int x, int y, int area, int n) {
    int sum = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty() && area > 0) {
        auto [cx, cy] = q.front();
        q.pop();
        sum += farm[cx][cy];
        area--;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (isValid(nx, ny, n) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> farm(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> farm[i][j];

    int maxTrees = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxTrees = max(maxTrees, bfsMaxTrees(farm, i, j, m, n));
        }
    }

    cout << maxTrees << endl;
    return 0;
}
