/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Z, Y, X;
vector<vector<string>> maze;
vector<vector<vector<bool>>> visited;
vector<char> path;

char move_chars[] = {'R', 'D', 'L', 'F', 'U', 'B'};
int dz[] = {0, 0, 0, 1, 0, -1};
int dy[] = {0, 1, 0, 0, -1, 0};
int dx[] = {1, 0, -1, 0, 0, 0};

bool solve(int z, int y, int x) {
    if (z == Z - 1 && y == Y - 1 && x == X - 1) {
        return true;
    }

    visited[z][y][x] = true;

    for (int i = 0; i < 6; ++i) {
        int nz = z + dz[i];
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nz >= 0 && nz < Z && ny >= 0 && ny < Y && nx >= 0 && nx < X &&
            maze[nz][ny][nx] == '.' && !visited[nz][ny][nx]) {
            
            path.push_back(move_chars[i]);
            if (solve(nz, ny, nx)) {
                return true;
            }
            path.pop_back();
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Z >> Y >> X;

    maze.resize(Z, vector<string>(Y));
    visited.resize(Z, vector<vector<bool>>(Y, vector<bool>(X, false)));

    for (int z = 0; z < Z; ++z) {
        for (int y = 0; y < Y; ++y) {
            cin >> maze[z][y];
        }
    }

    solve(0, 0, 0);

    cout << path.size() << endl;

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
    }
    cout << endl;

    return 0;
}
