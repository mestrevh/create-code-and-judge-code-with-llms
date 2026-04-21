/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> nomes(5);
    vector<int> idades(5);

    for (int i = 0; i < 5; i++) {
        if (!getline(cin, nomes[i])) return 0;
        double x;
        if (!(cin >> x)) return 0;
        x = fabs(x);
        idades[i] = static_cast<int>(x);
        string dummy;
        getline(cin, dummy);
    }

    cout << "Pessoa: " << nomes[0] << " , " << idades[0] << "\n";
    for (int i = 1; i < 5; i++) {
        cout << "Pessoa: " << nomes[i] << " , " << idades[i] << "\n";
    }

    long long soma = 0;
    for (int v : idades) soma += v;
    cout << soma << "\n";

    double mediaArit = soma / 5.0;
    cout << fixed << setprecision(1) << mediaArit << "\n";

    long double prod = 1.0L;
    for (int v : idades) prod *= (long double)v;
    long long mediaGeomTrunc = (long long)floor(powl(prod, 1.0L / 5.0L));
    cout << mediaGeomTrunc << "\n";

    return 0;
}