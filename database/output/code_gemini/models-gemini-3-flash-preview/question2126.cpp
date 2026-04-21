/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int grid[10][10];
bool visited[10][10];

bool find_path(int r, int c) {
    if (r == 9 && c == 9) {
        return true;
    }

    visited[r][c] = true;

    // Priority: South > East > North > West
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10) {
            if (grid[nr][nc] == 1 && !visited[nr][nc]) {
                if (find_path(nr, nc)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (!(cin >> grid[i][j])) return 0;
            visited[i][j] = false;
        }
    }

    // Starting point is always 1 as per description
    if (grid[0][0] == 1 && find_path(0, 0)) {
        cout << "RUN!" << endl;
    } else {
        cout << "Welcome to the Upside Down." << endl;
    }

    return 0;
}