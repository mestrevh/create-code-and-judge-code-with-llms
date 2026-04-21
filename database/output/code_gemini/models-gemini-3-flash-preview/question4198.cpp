/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    // Horizontal Search
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - k; j++) {
            bool ok = true;
            for (int m = 0; m < k / 2; m++) {
                if (mat[i][j + m] != mat[i][j + k - 1 - m]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "(" << i << ", " << j << ")" << endl;
                return 0;
            }
        }
    }

    // Vertical Search
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= n - k; i++) {
            bool ok = true;
            for (int m = 0; m < k / 2; m++) {
                if (mat[i + m][j] != mat[i + k - 1 - m][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "(" << i << ", " << j << ")" << endl;
                return 0;
            }
        }
    }

    // Diagonal Search (Main Diagonal: Top-Left to Bottom-Right)
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            bool ok = true;
            for (int m = 0; m < k / 2; m++) {
                if (mat[i + m][j + m] != mat[i + k - 1 - m][j + k - 1 - m]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "(" << i << ", " << j << ")" << endl;
                return 0;
            }
        }
    }

    // Diagonal Search (Anti-Diagonal: Top-Right to Bottom-Left)
    for (int i = 0; i <= n - k; i++) {
        for (int j = k - 1; j < n; j++) {
            bool ok = true;
            for (int m = 0; m < k / 2; m++) {
                // Check character at offset m from (i, j) against character at offset k-1-m
                if (mat[i + m][j - m] != mat[i + k - 1 - m][j - (k - 1 - m)]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "(" << i << ", " << j << ")" << endl;
                return 0;
            }
        }
    }

    cout << "(-1, -1)" << endl;

    return 0;
}