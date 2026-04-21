/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Avelino has a mosaic with holes (represented by 0). He wants to fill all holes 
 * with a single color C, which can be an existing color or a new one.
 * He wants to choose C to minimize the size of the smallest monochromatic area in 
 * the resulting mosaic.
 * 
 * Let A be the set of original monochromatic areas of non-zero colors.
 * Let Z be the set of original connected components of holes (0s).
 * If we pick color C:
 * 1. Monochromatic areas of color K != C remain unchanged.
 * 2. All 0s and all original tiles of color C merge if they are adjacent.
 * 
 * Because merging always creates areas of size greater than or equal to the 
 * original areas, the minimum area size in any filled mosaic cannot be smaller 
 * than the minimum area size in the mosaic where holes are treated as their own color.
 * By picking a new color C' that is not adjacent to any of the smallest existing areas,
 * the minimum area size in the final mosaic will be exactly the minimum size among 
 * all connected components in the original grid (including 0s).
 * Thus, the task reduces to finding the smallest connected component in the grid.
 */

int H, L;
int grid[205][205];
bool visited[205][205];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read height and width
    if (!(cin >> H >> L)) return 0;

    // Read grid colors
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            cin >> grid[i][j];
        }
    }

    int min_area = H * L;

    // Standard BFS to find monochromatic connected components
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < L; j++) {
            if (!visited[i][j]) {
                int color = grid[i][j];
                int current_area_size = 0;
                
                // BFS queue using pair of row and column
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    current_area_size++;

                    int r = curr.first;
                    int c = curr.second;

                    // Check all 4 adjacent neighbors
                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];

                        // Validate grid boundaries and color consistency
                        if (nr >= 0 && nr < H && nc >= 0 && nc < L &&
                            !visited[nr][nc] && grid[nr][nc] == color) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                
                // Update global minimum area size
                if (current_area_size < min_area) {
                    min_area = current_area_size;
                }
            }
        }
    }

    // Output the smallest area found
    cout << min_area << endl;

    return 0;
}