/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Matrix Multiplication Implementation
 * Time Complexity: O(N*M + A*B + N*B*M)
 * Space Complexity: O(N*M + A*B)
 */

int main() {
    // Optimization for Competitive Programming I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    
    // Read dimensions for Matrix 1 (n x m) and Matrix 2 (a x b)
    if (!(cin >> n >> m >> a >> b)) return 0;

    // Read Matrix 1
    vector<vector<long long>> mat1(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat1[i][j];
        }
    }

    // Read Matrix 2
    vector<vector<long long>> mat2(a, vector<long long>(b));
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            cin >> mat2[i][j];
        }
    }

    // Matrix multiplication is possible if columns of Matrix 1 equals rows of Matrix 2
    if (m != a) {
        cout << "Nao eh possivel multiplicar!" << endl;
        return 0;
    }

    // Resulting matrix will be n x b
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b; ++j) {
            long long sum = 0;
            for (int k = 0; k < m; ++k) {
                sum += mat1[i][k] * mat2[k][j];
            }
            // Printing logic with space separation
            cout << sum << (j == b - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}