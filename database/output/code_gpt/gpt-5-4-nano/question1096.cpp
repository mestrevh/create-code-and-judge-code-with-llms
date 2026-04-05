/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;

    const double PI = 3.14;

    double S = 0.0;
    for (long long k = 1; k <= N; k++) {
        double term = (double)k * PI;
        if (k % 2 == 1) S += term;
        else S -= term;
    }

    cout << fixed << setprecision(2) << "Valor de S : " << S;
    return 0;
}