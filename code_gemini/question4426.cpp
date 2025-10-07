/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        int magic_sum = 0;
        for (int j = 0; j < n; ++j) {
            magic_sum += matrix[0][j];
        }

        bool is_magic = true;

        for (int i = 1; i < n; ++i) {
            int row_sum = 0;
            for (int j = 0; j < n; ++j) {
                row_sum += matrix[i][j];
            }
            if (row_sum != magic_sum) {
                is_magic = false;
                break;
            }
        }

        if (is_magic) {
            for (int j = 0; j < n; ++j) {
                int col_sum = 0;
                for (int i = 0; i < n; ++i) {
                    col_sum += matrix[i][j];
                }
                if (col_sum != magic_sum) {
                    is_magic = false;
                    break;
                }
            }
        }

        if (is_magic) {
            int diag1_sum = 0;
            for (int i = 0; i < n; ++i) {
                diag1_sum += matrix[i][i];
            }
            if (diag1_sum != magic_sum) {
                is_magic = false;
            }
        }

        if (is_magic) {
            int diag2_sum = 0;
            for (int i = 0; i < n; ++i) {
                diag2_sum += matrix[i][n - 1 - i];
            }
            if (diag2_sum != magic_sum) {
                is_magic = false;
            }
        }

        if (is_magic) {
            cout << "Eh quadrado magico!!!" << endl;
        } else {
            cout << "Nao eh!!!" << endl;
        }
    }

    return 0;
}
