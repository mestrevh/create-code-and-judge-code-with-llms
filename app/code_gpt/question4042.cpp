/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows;
    cin.ignore();
    cin >> cols;
    cin.ignore();

    vector<string> maze(rows);
    for (int i = 0; i < rows; ++i) {
        cin >> maze[i];
    }

    pair<int, int> start, end;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 'o') start = {i, j};
            if (maze[i][j] == 'd') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<int>> distance(rows, vector<int>(cols, -1));
    q.push(start);
    visited[start.first][start.second] = true;
    distance[start.first][start.second] = 0;

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && maze[nx][ny] != '#') {
                visited[nx][ny] = true;
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (distance[end.first][end.second] != -1) {
        cout << "Apos correr " << distance[end.first][end.second] << " metros e quase desistir por causa da distância, Rebeka conseguiu escapar!" << endl;
    } else {
        cout << "Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir" << endl;
    }

    return 0;
}
