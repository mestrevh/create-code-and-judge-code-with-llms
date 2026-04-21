/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Matrix {
    double m[10][10];
    int n;

    Matrix(int size) : n(size) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                m[i][j] = 0.0;
            }
        }
    }

    static Matrix identity(int n) {
        Matrix res(n);
        for (int i = 0; i < n; ++i) {
            res.m[i][i] = 1.0;
        }
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(n);
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                double val = m[i][k];
                if (val == 0.0) continue;
                for (int j = 0; j < n; ++j) {
                    res.m[i][j] += val * other.m[k][j];
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    while (cin >> n >> k) {
        Matrix base(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> base.m[i][j];
            }
        }

        Matrix res = Matrix::identity(n);
        Matrix p = base;
        while (k > 0) {
            if (k % 2 == 1) {
                res = res * p;
            }
            p = p * p;
            k /= 2;
        }

        cout << fixed << setprecision(3);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << res.m[i][j] << (j == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}