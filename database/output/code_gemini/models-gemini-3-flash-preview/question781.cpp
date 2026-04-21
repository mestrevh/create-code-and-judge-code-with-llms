/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<int>> mat(L, vector<int>(C));
    int min_r = 0, max_r = L - 1;
    int min_c = 0, max_c = C - 1;
    int val = 1;

    while (min_r <= max_r && min_c <= max_c) {
        // Step 1: Fill the leftmost available column from top to bottom
        for (int i = min_r; i <= max_r; ++i) {
            mat[i][min_c] = val++;
        }
        if (min_c == max_c) break;

        // Step 2: Fill the rightmost available column from bottom to top
        for (int i = max_r; i >= min_r; --i) {
            mat[i][max_c] = val++;
        }

        // Step 3: Fill the bottom available row (middle section) from left to right
        for (int j = min_c + 1; j < max_c; ++j) {
            mat[max_r][j] = val++;
        }
        if (min_r == max_r) break;

        // Step 4: Fill the top available row (middle section) from left to right
        for (int j = min_c + 1; j < max_c; ++j) {
            mat[min_r][j] = val++;
        }

        // Shrink the boundaries for the next inner layer
        min_r++;
        max_r--;
        min_c++;
        max_c--;
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << setfill('0') << setw(3) << mat[i][j] << (j == C - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}