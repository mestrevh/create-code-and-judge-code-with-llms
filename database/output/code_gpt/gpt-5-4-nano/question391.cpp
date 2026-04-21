/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<long double>> A(n, vector<long double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> A[i][j];
    }

    vector<long double> y(n);
    for (int i = 0; i < n; i++) cin >> y[i];

    long long maxIter;
    cin >> maxIter;

    long double tol1, tol2;
    cin >> tol1 >> tol2;

    vector<long double> z(n), ynew(n);
    vector<long double> yk = y;

    auto norm = [&](const vector<long double>& v) -> long double {
        long double s = 0;
        for (auto &x : v) s += x * x;
        return sqrtl(s);
    };

    auto rayleigh = [&](const vector<long double>& v) -> long double {
        vector<long double> Av(n);
        for (int i = 0; i < n; i++) {
            long double sum = 0;
            for (int j = 0; j < n; j++) sum += A[i][j] * v[j];
            Av[i] = sum;
        }
        long double num = 0, den = 0;
        for (int i = 0; i < n; i++) {
            num += v[i] * Av[i];
            den += v[i] * v[i];
        }
        if (fabsl(den) < tol2) return 0;
        return num / den;
    };

    long double lb_prev = 0;
    bool have_prev = false;

    for (long long k = 1; k <= maxIter; k++) {
        for (int i = 0; i < n; i++) {
            long double sum = 0;
            for (int j = 0; j < n; j++) sum += A[i][j] * yk[j];
            z[i] = sum;
        }

        long double zn = norm(z);
        if (fabsl(zn) < tol2) {
            cout.setf(std::ios::fixed);
            cout << setprecision(4);
            for (int i = 0; i < n; i++) {
                if (i) cout << "\n";
                cout << "v1_" << k << "\n";
                break;
            }
            for (int i = 0; i < n; i++) {
                cout << fixed << setprecision(4) << yk[i] << "\n";
            }
            cout << "lb1_" << k << "\n";
            cout << fixed << setprecision(4) << 0.0L << "\n";
            cout << "\n";
            cout << "Divisao por zero na iteracao " << k << ".";
            return 0;
        }

        for (int i = 0; i < n; i++) ynew[i] = z[i] / zn;

        long double lb = rayleigh(ynew);

        if (k == 1) {
            lb_prev = lb;
            have_prev = true;
        } else {
            long double denom = lb;
            if (fabsl(denom) < tol2) {
                cout.setf(std::ios::fixed);
                cout << setprecision(4);
                for (int i = 0; i < n; i++) {
                    cout << "v1_" << k << "\n";
                    break;
                }
                for (int i = 0; i < n; i++) {
                    cout << fixed << setprecision(4) << ynew[i] << "\n";
                }
                cout << "lb1_" << k << "\n";
                cout << fixed << setprecision(4) << lb << "\n";
                cout << "\n";
                cout << "Divisao por zero na iteracao " << k << ".";
                return 0;
            }
            long double err = fabsl((lb - lb_prev) / lb);
            cout.setf(std::ios::fixed);
            cout << setprecision(4);
            if (k > 1) cout << "\n\n";
            cout << "v1_" << k << "\n";
            for (int i = 0; i < n; i++) cout << fixed << setprecision(4) << ynew[i] << "\n";
            cout << "lb1_" << k << "\n";
            cout << fixed << setprecision(4) << lb << "\n";
            if (err < tol1) {
                cout << "\n";
                cout << "Algoritmo converge com " << k << " iteracoes.";
                return 0;
            }
            lb_prev = lb;
        }

        if (k == 1) {
            cout.setf(std::ios::fixed);
            cout << setprecision(4);
            cout << "v1_" << k << "\n";
            for (int i = 0; i < n; i++) cout << fixed << setprecision(4) << ynew[i] << "\n";
            cout << "lb1_" << k << "\n";
            cout << fixed << setprecision(4) << lb << "\n";
        } else {
            yk = ynew;
            continue;
        }

        yk = ynew;
    }

    if (maxIter >= 1) {
        if (maxIter > 1) {
        }
    }

    cout << "\n";
    cout << "Atingiu o numero maximo de iteracoes.";
    return 0;
}