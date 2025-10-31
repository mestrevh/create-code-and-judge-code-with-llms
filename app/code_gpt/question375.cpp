/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void matrix_mult(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &C) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_sub(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &C) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void matrix_identity(vector<vector<double>> &I, int n) {
    I.assign(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        I[i][i] = 1;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<double> s(n - 1);
    vector<double> p(n);
    vector<vector<double>> B(n, vector<double>(n, 0));
    vector<vector<double>> I(n);
    matrix_identity(I, n);

    B = A;

    for (int k = 1; k < n; ++k) {
        double trace = 0;
        for (int i = 0; i < n; ++i)
            trace += B[i][i];
        s[k - 1] = trace;

        vector<vector<double>> temp(n);
        matrix_mult(B, A, temp);
        B = temp;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                B[i][j] = (i == j) ? (B[i][j] - s[k - 1] * I[i][j]) : B[i][j];
    }

    for (int i = 1; i < n; ++i) {
        p[i] = -s[i - 1];
        if (fabs(p[i]) < 1e-10) p[i] = 0;
    }

    cout << fixed << setprecision(2);
    for (const auto &val : s) {
        cout << val << "e+00 ";
    }
    cout << endl;
    for (const auto &val : p) {
        cout << val << "e+00 ";
    }
    cout << endl;

    return 0;
}
