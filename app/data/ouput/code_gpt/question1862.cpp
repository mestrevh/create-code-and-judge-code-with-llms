/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <unordered_set>

using namespace std;

struct Cell {
    int x, y, height;
    string path;
};

vector<string> directions = { "N", "L", "S", "O" };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool isValid(int x, int y, int M, const vector<vector<bool>>& walls) {
    return x >= 0 && x < M && y >= 0 && y < M && !walls[x][y];
}

void dfs(int x, int y, int R, int M, const vector<vector<int>>& heights, 
         const vector<vector<bool>>& walls, unordered_set<int>& visited,
         vector<Cell>& results, string currentPath, int steps) {
    if (steps > R) return;
    int id = x * M + y;
    if (visited.count(id)) return; 
    visited.insert(id);
    
    if (results.empty() || heights[x][y] > results[0].height) {
        results.clear();
        results.push_back({x, y, heights[x][y], currentPath});
    } else if (heights[x][y] == results[0].height) {
        results.push_back({x, y, heights[x][y], currentPath});
    }
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, M, walls)) {
            dfs(nx, ny, R, M, heights, walls, visited, results, currentPath + directions[i], steps + 1);
        }
    }
}

int main() {
    int M;
    cin >> M;

    vector<vector<int>> heights(M, vector<int>(M));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            cin >> heights[i][j];

    int W;
    cin >> W;

    vector<vector<bool>> walls(M, vector<bool>(M, false));
    for (int i = 0; i < W; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        walls[x1][y1] = true;
        walls[x2][y2] = true;
    }

    int R, K;
    cin >> R >> K;
    for (int caseNum = 0; caseNum < K; ++caseNum) {
        int startX, startY;
        cin >> startX >> startY;

        unordered_set<int> visited;
        vector<Cell> results;
        dfs(startX, startY, R, M, heights, walls, visited, results, "", 0);

        cout << "caso " << caseNum << ":\n";
        for (size_t i = 0; i < results.size(); ++i) {
            cout << results[i].path << "=" << results[i].height << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}
