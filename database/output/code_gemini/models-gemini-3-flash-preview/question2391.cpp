/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// The dimensions are up to 200x200, so a fixed-size array is efficient.
char grid[205][205];

/**
 * Recursive function to reconstruct the bitmap matrix from its compact string representation.
 * 
 * @param r1 Starting row index of the current quadrant
 * @param c1 Starting column index of the current quadrant
 * @param r2 Ending row index of the current quadrant
 * @param c2 Ending column index of the current quadrant
 */
void build_matrix(int r1, int c1, int r2, int c2) {
    // If the dimensions are invalid (0 area), return without consuming characters.
    if (r1 > r2 || c1 > c2) {
        return;
    }

    char ch;
    // Read the next character from the compact representation string.
    // Skip any potential whitespace automatically.
    if (!(cin >> ch)) return;

    if (ch == 'D') {
        // Calculate height and width of the current region.
        int h = r2 - r1 + 1;
        int w = c2 - c1 + 1;
        
        // Define split points based on the problem's rules:
        // "When the number of columns is odd, the left quadrants have one more column."
        // "When the number of rows is odd, the top quadrants have one more row."
        int h_top = (h + 1) / 2;
        int w_left = (w + 1) / 2;

        // Recursively process the four quadrants in the specified order:
        // Top-Left
        build_matrix(r1, c1, r1 + h_top - 1, c1 + w_left - 1);
        // Top-Right
        build_matrix(r1, c1 + w_left, r1 + h_top - 1, c2);
        // Bottom-Left
        build_matrix(r1 + h_top, c1, r2, c1 + w_left - 1);
        // Bottom-Right
        build_matrix(r1 + h_top, c1 + w_left, r2, c2);
    } else {
        // Fill the defined rectangular region with '0' or '1'.
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                grid[i][j] = ch;
            }
        }
    }
}

int main() {
    // Optimization for C++ standard I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    if (!(cin >> T)) return 0;

    for (int t = 0; t < T; ++t) {
        int n, m;
        // Read the dimensions for the current test case.
        if (!(cin >> n >> m)) break;

        // Process the hierarchical string and fill the grid.
        build_matrix(0, 0, n - 1, m - 1);

        // Print the reconstructed matrix. 
        // Separate test cases with a blank line as requested.
        if (t > 0) {
            cout << "\n";
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}

