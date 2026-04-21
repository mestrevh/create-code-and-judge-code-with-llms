/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char type;
    int r, c;
    if (cin >> type >> r >> c) {
        vector<vector<int>> mat(r, vector<int>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> mat[i][j];
            }
        }

        if (type == 'V') {
            // Vertical cut: the "right part" (columns from c/2 to c-1) is inverted vertically.
            // This means for each column in the right part, reverse the order of its rows.
            for (int j = c / 2; j < c; ++j) {
                for (int i = 0; i < r / 2; ++i) {
                    swap(mat[i][j], mat[r - 1 - i][j]);
                }
            }
        } else if (type == 'H') {
            // Horizontal cut: the "bottom part" (rows from r/2 to r-1) is inverted horizontally.
            // This means for each row in the bottom part, reverse the order of its elements.
            for (int i = r / 2; i < r; ++i) {
                for (int j = 0; j < c / 2; ++j) {
                    swap(mat[i][j], mat[i][c - 1 - j]);
                }
            }
        }

        // Output the matrix, formatting each number with at least two digits (prefilled with 0).
        // Each number is followed by a space, as per the test case examples.
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << setfill('0') << setw(2) << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}