/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Perform a recursive search in a column-major order to find the target locker (value 0).
 * If a negative value is encountered, the process stops with a discovery message.
 * @param n Number of corridors (rows)
 * @param y Number of lockers per corridor (columns)
 * @param grid The matrix representing the lockers
 * @param r Current corridor being checked (0-indexed)
 * @param c Current locker being checked in the corridor (0-indexed)
 */
void recursiveSearch(int n, int y, const vector<vector<int>>& grid, int r, int c) {
    // If column index equals or exceeds total lockers, target was not found
    if (c >= y) {
        cout << "Sharpay endoidou!" << endl;
        return;
    }

    // Discovery condition: a negative value is encountered
    if (grid[r][c] < 0) {
        cout << "Voce foi descoberto! Corra dancando Bop To the Top!!" << endl;
        return;
    }

    // Success condition: the value 0 is found
    if (grid[r][c] == 0) {
        cout << "O armario a ser invadido fica no corredor " << r + 1 
             << ", e e o armario de numero " << c + 1 << "." << endl;
        return;
    }

    // Determine the next locker coordinates in column-major order
    int next_r = r + 1;
    int next_c = c;
    if (next_r >= n) {
        next_r = 0;
        next_c = c + 1;
    }

    // Recursive call to search the next locker
    recursiveSearch(n, y, grid, next_r, next_c);
}

int main() {
    // Optimization of standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, y;
    // Attempt to read the number of corridors and lockers
    if (!(cin >> n >> y)) {
        return 0;
    }

    // Validation: check if search is possible
    if (n <= 0 || y <= 0) {
        cout << "Sharpay endoidou!" << endl;
        return 0;
    }

    // Allocate and populate the grid representing the corridors and lockers
    vector<vector<int>> grid(n, vector<int>(y));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < y; ++j) {
            if (!(cin >> grid[i][j])) break;
        }
    }

    // Initiate the recursive search starting from (0, 0)
    recursiveSearch(n, y, grid, 0, 0);

    return 0;
}