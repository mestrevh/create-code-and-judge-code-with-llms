/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Ship structure to store coordinates and survival status.
 * Coordinates use a 0-indexed system consistent with matrix dimensions.
 */
struct Ship {
    int x, y;
    bool alive;
};

/**
 * Function to print the N x M grid based on the current list of ships.
 * Ships mark their position with a '1', empty spaces with '0'.
 */
void print_grid(int N, int M, const vector<Ship>& ships) {
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (const auto& s : ships) {
        if (s.alive) {
            grid[s.x][s.y] = 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << grid[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

/**
 * Logic:
 * 1. Read dimensions N, M.
 * 2. Read initial K ships and print initial grid.
 * 3. Read H attacks, each with B bombs.
 * 4. For each hour (attack):
 *    - Define hit zones for all B bombs (center + 4 diagonals).
 *    - Use toroidal wrap-around (x % N, y % M) for all points.
 *    - Check each ship against hit zones; mark destroyed ships as !alive.
 *    - Move surviving ships to their new coordinates (x-1, y+1) with wrap-around.
 *    - Print the resulting grid for that hour.
 */
int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    int K;
    if (!(cin >> K)) return 0;
    vector<Ship> ships(K);
    for (int i = 0; i < K; ++i) {
        cin >> ships[i].x >> ships[i].y;
        ships[i].alive = true;
    }

    // Output initial fleet state
    print_grid(N, M, ships);

    int H, B;
    if (!(cin >> H >> B)) return 0;

    // Displacement vectors for the X-shaped bomb pattern (center + 4 closest diagonals)
    const int dx[] = {0, 1, 1, -1, -1};
    const int dy[] = {0, 1, -1, -1, 1};

    for (int h = 0; h < H; ++h) {
        // Local grid to mark areas destroyed by current set of B bombs
        vector<vector<bool>> hit(N, vector<bool>(M, false));
        for (int b = 0; b < B; ++b) {
            int bx, by;
            if (!(cin >> bx >> by)) break;
            
            for (int i = 0; i < 5; ++i) {
                int nx = (bx + dx[i]) % N;
                if (nx < 0) nx += N;
                int ny = (by + dy[i]) % M;
                if (ny < 0) ny += M;
                hit[nx][ny] = true;
            }
        }

        // Process ship survival and movement
        for (auto& s : ships) {
            if (s.alive) {
                if (hit[s.x][s.y]) {
                    // Ship is in a destroyed zone
                    s.alive = false;
                } else {
                    // Ship survives and moves to diagonal superior right (x-1, y+1)
                    s.x = (s.x - 1 + N) % N;
                    s.y = (s.y + 1) % M;
                }
            }
        }

        // Output grid after this attack's resolution and fleet movement
        cout << "\n";
        print_grid(N, M, ships);
    }

    return 0;
}