/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    vector<double> vals;
    double v;
    while (scanf("%lf", &v) != EOF) {
        vals.push_back(v);
    }

    if (vals.empty()) return 0;

    int n = (int)round(sqrt((double)vals.size()));
    if (n == 0) return 0;

    vector<vector<long double>> A(n, vector<long double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (long double)vals[i * n + j];
        }
    }

    vector<long double> s(n + 1);
    vector<vector<long double>> Ak = A;
    vector<vector<long double>> Anext(n, vector<long double>(n));

    long double tr1 = 0;
    for (int i = 0; i < n; ++i) tr1 += A[i][i];
    s[1] = tr1;

    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long double sum = 0;
                for (int l = 0; l < n; ++l) {
                    sum += Ak[i][l] * A[l][j];
                }
                Anext[i][j] = sum;
            }
        }
        Ak = Anext;
        long double trk = 0;
        for (int i = 0; i < n; ++i) trk += Ak[i][i];
        s[k] = trk;
    }

    vector<long double> p(n + 1);
    for (int k = 1; k <= n; ++k) {
        long double sum_ps = 0;
        for (int j = 1; j < k; ++j) {
            sum_ps += p[j] * s[k - j];
        }
        p[k] = -(s[k] + sum_ps) / (long double)k;
    }

    for (int k = 1; k <= n; ++k) {
        printf("%.2e ", (double)s[k]);
    }
    printf("\n");

    for (int k = 1; k <= n; ++k) {
        long double val_p_ld = p[k];
        if (fabsl(val_p_ld) < 1e-10L) val_p_ld = 0.0L;
        printf("%.2e ", (double)val_p_ld);
    }
    printf("\n");

    return 0;
}