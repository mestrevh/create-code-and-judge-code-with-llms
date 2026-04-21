/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int n;
    vector<vector<double>> a;
    Matrix(int n_=0, bool ident=false): n(n_), a(n_, vector<double>(n_, 0.0)) {
        if (ident) for (int i=0;i<n;i++) a[i][i]=1.0;
    }
};

static Matrix multiply(const Matrix& x, const Matrix& y) {
    int n = x.n;
    Matrix r(n);
    for (int i=0;i<n;i++) {
        for (int k=0;k<n;k++) {
            double xik = x.a[i][k];
            if (xik==0.0) continue;
            for (int j=0;j<n;j++) {
                r.a[i][j] += xik * y.a[k][j];
            }
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cout.setf(std::ios::fixed);
    cout << setprecision(3);

    while ( (cin >> n >> k) ) {
        Matrix base(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> base.a[i][j];
            }
        }

        Matrix res(n, true);
        Matrix cur = base;

        while (k > 0) {
            if (k & 1LL) res = multiply(res, cur);
            k >>= 1LL;
            if (k) cur = multiply(cur, cur);
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (j) cout << ' ';
                double v = res.a[i][j];
                if (abs(v) < 0.0005) v = 0.0;
                cout << v;
            }
            cout << "\n";
        }
    }
    return 0;
}