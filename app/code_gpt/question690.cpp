/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef vector<vector<double>> Matrix;

Matrix multiply(const Matrix &a, const Matrix &b, int n) {
    Matrix c(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

Matrix power(Matrix a, long long p, int n) {
    Matrix result(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) result[i][i] = 1;
    while (p) {
        if (p % 2)
            result = multiply(result, a, n);
        a = multiply(a, a, n);
        p /= 2;
    }
    return result;
}

int main() {
    int n;
    long long k;
    while (cin >> n >> k) {
        Matrix mat(n, vector<double>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> mat[i][j];

        Matrix result = power(mat, k, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(3) << result[i][j] << (j < n - 1 ? ' ' : '\n');
            }
        }
    }
    return 0;
}
