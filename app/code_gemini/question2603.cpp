/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool find_path(int r, int c, int m, int n, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    if (r < 0 || r >= m || c < 0 || c >= n) {
        return false;
    }

    if (grid[r][c] == '#' || visited[r][c]) {
        return false;
    }

    if (grid[r][c] == 'S') {
        return true;
    }

    visited[r][c] = true;

    // Up
    if (find_path(r - 1, c, m, n, grid, visited)) {
        return true;
    }
    // Right
    if (find_path(r, c + 1, m, n, grid, visited)) {
        return true;
    }
    // Down
    if (find_path(r + 1, c, m, n, grid, visited)) {
        return true;
    }
    // Left
    if (find_path(r, c - 1, m, n, grid, visited)) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));
    int start_r = -1, start_c = -1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                start_r = i;
                start_c = j;
            }
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    if (start_r != -1 && find_path(start_r, start_c, m, n, grid, visited)) {
        cout << "Esse Yordle é confiável, vamos por esse atalho." << endl;
    } else {
        cout << "Não tem saída, deve ser a LeBlanc tentando me enganar, melhor dar o fora daqui." << endl;
    }

    return 0;
}
