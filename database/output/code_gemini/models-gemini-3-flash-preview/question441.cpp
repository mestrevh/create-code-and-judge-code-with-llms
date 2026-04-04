/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Seasonal War / Guerra Sazonal
 * Goal: Count the number of connected components of '1' pixels in a grid.
 * Connectivity: 8-way (adjacent sides or vertices).
 * Complexity: O(N^2) per test case, where N is the grid dimension.
 */

int main() {
    // Standard CP optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int imageCount = 1;

    // Read the dimension of the square image
    while (cin >> n) {
        // Read the n x n grid character by character
        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        // Keep track of visited pixels to count each installation once
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int warEagles = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If a new military installation is found
                if (grid[i][j] == '1' && !visited[i][j]) {
                    warEagles++;
                    
                    // Perform iterative DFS to mark all pixels of this installation
                    vector<pair<int, int>> st;
                    st.push_back({i, j});
                    visited[i][j] = true;

                    while (!st.empty()) {
                        pair<int, int> curr = st.back();
                        st.pop_back();

                        // Check all 8 neighboring cells
                        for (int dr = -1; dr <= 1; ++dr) {
                            for (int dc = -1; dc <= 1; ++dc) {
                                // Skip the center cell itself
                                if (dr == 0 && dc == 0) continue;

                                int ni = curr.first + dr;
                                int nj = curr.second + dc;

                                // Check bounds and connectivity
                                if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                                    grid[ni][nj] == '1' && !visited[ni][nj]) {
                                    visited[ni][nj] = true;
                                    st.push_back({ni, nj});
                                }
                            }
                        }
                    }
                }
            }
        }

        // Output the result in the exact format required
        cout << "Image number " << imageCount++ << " contains " << warEagles << " war eagles.\n";
    }

    return 0;
}