/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

int Z, Y, X;
vector<vector<vector<char>>> maze;
vector<string> directions = {"U", "D", "L", "R", "F", "B"};
vector<tuple<int, int, int>> moves = {{-1, 0, 0}, {1, 0, 0}, {0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}};
vector<string> path;
bool found = false;

void backtrack(int z, int y, int x) {
    if (z < 0 || z >= Z || y < 0 || y >= Y || x < 0 || x >= X || maze[z][y][x] == '#') return;
    if (z == Z - 1 && y == Y - 1 && x == X - 1) {
        found = true;
        return;
    }

    char temp = maze[z][y][x];
    maze[z][y][x] = '#';

    for (int i = 0; i < 6; ++i) {
        int nz = z + get<0>(moves[i]);
        int ny = y + get<1>(moves[i]);
        int nx = x + get<2>(moves[i]);
        if (found) break;
        path.push_back(directions[i]);
        backtrack(nz, ny, nx);
        if (!found) path.pop_back();
    }

    maze[z][y][x] = temp;
}

int main() {
    cin >> Z >> Y >> X;
    maze.resize(Z, vector<vector<char>>(Y, vector<char>(X)));
    for (int z = 0; z < Z; ++z) {
        for (int y = 0; y < Y; ++y) {
            for (int x = 0; x < X; ++x) {
                cin >> maze[z][y][x];
            }
        }
        if (z < Z - 1) cin.ignore();
    }

    backtrack(0, 0, 0);

    cout << path.size() << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        if (i > 0) cout << " -> ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}
