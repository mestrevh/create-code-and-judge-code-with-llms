/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Tower Defense
 * Goal: Verify if all enemies ('*') are within a range of 1 from at least one tower ('&').
 * Range 1 in a grid typically means the 8 surrounding cells plus the cell itself (Chebyshev distance <= 1).
 * 
 * Complexity: O(H * C), where H is height and C is width.
 * This is optimal as we must inspect each cell at least once.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, C;
    if (!(cin >> H >> C)) return 0;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    bool all_covered = true;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < C; ++j) {
            // If we find an enemy, check if there's any tower in range 1
            if (grid[i][j] == '*') {
                bool hit = false;
                // Check 3x3 area centered at (i, j)
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;
                        
                        // Check boundaries
                        if (ni >= 0 && ni < H && nj >= 0 && nj < C) {
                            if (grid[ni][nj] == '&') {
                                hit = true;
                                break;
                            }
                        }
                    }
                    if (hit) break;
                }
                
                if (!hit) {
                    all_covered = false;
                    break;
                }
            }
        }
        if (!all_covered) break;
    }

    if (all_covered) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}