/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void floodFill(vector<string>& grid, int x, int y, char mark, char contour) {
    int rows = grid.size();
    int cols = grid[0].size();
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != ' ')
        return;

    grid[x][y] = mark;

    floodFill(grid, x + 1, y, mark, contour);
    floodFill(grid, x - 1, y, mark, contour);
    floodFill(grid, x, y + 1, mark, contour);
    floodFill(grid, x, y - 1, mark, contour);
}

int main() {
    string line;
    vector<string> grid;

    while (getline(cin, line) && line != string(80, '_')) {
        grid.push_back(line);
    }
    grid.push_back(line);

    for (int i = 0; i < grid.size() - 1; i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '#') {
                floodFill(grid, i, j, '#', 'X');
            }
            else if (grid[i][j] == '/') {
                floodFill(grid, i, j, '/', 'X');
            }
        }
    }

    for (const auto& row : grid) {
        cout << row << endl;
    }

    return 0;
}
