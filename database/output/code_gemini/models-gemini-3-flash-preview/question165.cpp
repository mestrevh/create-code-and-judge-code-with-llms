/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    long long magic_sum = 0;
    for (int j = 0; j < n; ++j) {
        magic_sum += matrix[0][j];
    }

    bool is_magic = true;

    for (int i = 0; i < n; ++i) {
        long long current_row_sum = 0;
        for (int j = 0; j < n; ++j) {
            current_row_sum += matrix[i][j];
        }
        if (current_row_sum != magic_sum) {
            is_magic = false;
            break;
        }
    }

    if (is_magic) {
        for (int j = 0; j < n; ++j) {
            long long current_col_sum = 0;
            for (int i = 0; i < n; ++i) {
                current_col_sum += matrix[i][j];
            }
            if (current_col_sum != magic_sum) {
                is_magic = false;
                break;
            }
        }
    }

    if (is_magic) {
        long long diag1 = 0;
        long long diag2 = 0;
        for (int i = 0; i < n; ++i) {
            diag1 += matrix[i][i];
            diag2 += matrix[i][n - 1 - i];
        }
        if (diag1 != magic_sum || diag2 != magic_sum) {
            is_magic = false;
        }
    }

    if (is_magic) {
        cout << magic_sum << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}