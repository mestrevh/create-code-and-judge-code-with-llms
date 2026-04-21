/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int z, y, x;
};

int Z, Y, X;
char maze[70][70][70];
bool visited[70][70][70];
Node parent[70][70][70];
char moveTaken[70][70][70];

int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
char moveChar[] = {'U', 'D', 'L', 'R', 'F', 'B'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> Z >> Y >> X)) return 0;

    for (int z = 0; z < Z; ++z) {
        for (int y = 0; y < Y; ++y) {
            for (int x = 0; x < X; ++x) {
                cin >> maze[z][y][x];
                visited[z][y][x] = false;
            }
        }
    }

    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = true;

    bool found = false;
    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.z == Z - 1 && curr.y == Y - 1 && curr.x == X - 1) {
            found = true;
            break;
        }

        for (int i = 0; i < 6; ++i) {
            int nz = curr.z + dz[i];
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (nz >= 0 && nz < Z && ny >= 0 && ny < Y && nx >= 0 && nx < X &&
                maze[nz][ny][nx] == '.' && !visited[nz][ny][nx]) {
                visited[nz][ny][nx] = true;
                parent[nz][ny][nx] = curr;
                moveTaken[nz][ny][nx] = moveChar[i];
                q.push({nz, ny, nx});
            }
        }
    }

    if (found) {
        vector<char> path;
        Node curr = {Z - 1, Y - 1, X - 1};
        while (!(curr.z == 0 && curr.y == 0 && curr.x == 0)) {
            path.push_back(moveTaken[curr.z][curr.y][curr.x]);
            curr = parent[curr.z][curr.y][curr.x];
        }
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (int i = 0; i < (int)path.size(); ++i) {
            cout << path[i] << (i == (int)path.size() - 1 ? "" : " -> ");
        }
        cout << endl;
    }

    return 0;
}