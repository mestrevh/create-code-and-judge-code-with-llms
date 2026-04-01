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

    if (n <= 0) {
        return 0;
    }

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    bool is_permutation = true;

    for (int i = 0; i < n; ++i) {
        int count_ones = 0;
        int count_zeros = 0;
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                count_ones++;
            } else if (mat[i][j] == 0) {
                count_zeros++;
            } else {
                is_permutation = false;
            }
        }
        if (count_ones != 1 || count_zeros != (n - 1)) {
            is_permutation = false;
        }
    }

    if (is_permutation) {
        for (int j = 0; j < n; ++j) {
            int count_ones = 0;
            int count_zeros = 0;
            for (int i = 0; i < n; ++i) {
                if (mat[i][j] == 1) {
                    count_ones++;
                } else if (mat[i][j] == 0) {
                    count_zeros++;
                } else {
                    is_permutation = false;
                }
            }
            if (count_ones != 1 || count_zeros != (n - 1)) {
                is_permutation = false;
            }
        }
    }

    if (is_permutation) {
        cout << "True" << "\n";
    } else {
        cout << "False" << "\n";
    }

    return 0;
}