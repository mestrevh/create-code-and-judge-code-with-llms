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

    vector<double> v(n), u(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> u[i];

    long double dotUV = 0, dotUU = 0, dotVV = 0;
    for (int i = 0; i < n; i++) {
        dotUV += (long double)v[i] * (long double)u[i];
        dotUU += (long double)u[i] * (long double)u[i];
        dotVV += (long double)v[i] * (long double)v[i];
    }

    const long double EPS = 1e-9L;

    auto equalVectors = [&]() -> bool {
        for (int i = 0; i < n; i++) {
            if (fabsl((long double)v[i] - (long double)u[i]) > 1e-6L) return false;
        }
        return true;
    };

    cout.setf(std::ios::fixed);
    cout << setprecision(3);

    if (equalVectors()) {
        cout << "Os vetores sao iguais, logo, a projecao de v na direcao de u, eh o proprio u.";
        return 0;
    }

    long double factor = 0;
    if (fabsl(dotUU) > EPS) factor = dotUV / dotUU;

    cout << "A projecao ortogonal de v na direcao de u eh:\n";
    for (int i = 0; i < n; i++) {
        long double proj = factor * (long double)u[i];
        cout << "| " << (double)proj << " |\n";
    }
    return 0;
}