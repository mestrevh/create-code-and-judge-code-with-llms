/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int raizes(float A, float B, float C, float *x1, float *x2) {
    const float eps = 1e-6f;
    if (fabs(A) < eps) {
        if (fabs(B) < eps) {
            if (fabs(C) < eps) return 0;
            return 0;
        }
        float r = -C / B;
        if (x1) *x1 = r;
        if (x2) *x2 = r;
        return 1;
    }

    double delta = (double)B * (double)B - 4.0 * (double)A * (double)C;

    if (delta > eps) {
        double sd = sqrt(delta);
        double denom = 2.0 * (double)A;
        double r1 = ((double)-B - sd) / denom;
        double r2 = ((double)-B + sd) / denom;
        if (x1) *x1 = (float)r1;
        if (x2) *x2 = (float)r2;
        return 2;
    } else if (fabs(delta) <= eps) {
        double r = (double)-B / (2.0 * (double)A);
        if (x1) *x1 = (float)r;
        if (x2) *x2 = (float)r;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    float x1 = 0.0f, x2 = 0.0f;
    int qtd = raizes(A, B, C, &x1, &x2);

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    if (qtd >= 1) {
        cout << x1 << "\n";
        if (qtd == 2) cout << x2 << "\n";
    }
    cout << qtd << "\n";
    return 0;
}