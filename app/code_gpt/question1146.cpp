/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int H, L;
vector<vector<int>> grid;
unordered_set<int> colors;
vector<vector<bool>> visited;

int bfs(int x, int y, int color) {
    int size = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        size++;
        for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            int nx = cx + dx, ny = cy + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < L && !visited[nx][ny] && grid[nx][ny] == color) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return size;
}

int main() {
    cin >> H >> L;
    grid.resize(H, vector<int>(L));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < L; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != 0) colors.insert(grid[i][j]);
        }

    int min_area = INT_MAX;
    for (int color : colors) {
        visited.assign(H, vector<bool>(L, false));
        vector<int> areas;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < L; j++) {
                if (!visited[i][j] && grid[i][j] == color) {
                    areas.push_back(bfs(i, j, color));
                }
            }
        }
        if (!areas.empty()) {
            min_area = min(min_area, *min_element(areas.begin(), areas.end()));
        }
    }

    for (int color = 1; color <= 40000; color++) {
        if (!colors.count(color)) {
            visited.assign(H, vector<bool>(L, false));
            vector<int> areas;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < L; j++) {
                    if (!visited[i][j] && grid[i][j] == 0) {
                        areas.push_back(bfs(i, j, color));
                    }
                }
            }
            if (!areas.empty()) {
                min_area = min(min_area, *min_element(areas.begin(), areas.end()));
            }
        }
    }

    cout << min_area << endl;
    return 0;
}
