/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Sul, Leste, Norte, Oeste
const string dirNames[4] = {"Sul", "Leste", "Norte", "Oeste"};

bool dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited, vector<string>& path) {
    if (x == map.size() - 1 && y == map[0].size() - 1) {
        return true;
    }
    
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (newX >= 0 && newX < map.size() && newY >= 0 && newY < map[0].size()
            && !visited[newX][newY] && map[newX][newY] == 1) {
            path.push_back(dirNames[i]);
            if (dfs(newX, newY, map, visited, path)) {
                return true;
            }
            path.pop_back();
        }
    }

    return false;
}

string compressPath(const vector<string>& path) {
    unordered_map<string, int> count;
    for (const string& dir : path) {
        count[dir]++;
    }
    
    string result;
    for (const auto& [dir, cnt] : count) {
        result += (result.empty() ? "" : ", ") + 
                  (cnt > 1 ? to_string(cnt) + "*" + dir : dir);
    }
    return result;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> map(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    vector<string> path;

    if (dfs(0, 0, map, visited, path)) {
        cout << compressPath(path) << endl;
    } else {
        cout << "Welcome to the Upside Down." << endl;
    }

    return 0;
}
