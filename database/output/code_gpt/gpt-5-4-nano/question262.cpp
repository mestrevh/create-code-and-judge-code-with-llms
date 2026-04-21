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

    vector<double> a(n);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double media = sum / n;
    double sup = media * 1.10;
    double inf = media * 0.90;

    int acima = 0, abaixo = 0;
    for (double x : a) {
        if (x > sup) acima++;
        if (x < inf) abaixo++;
    }

    cout << fixed << setprecision(2) << media << "\n";
    cout << acima << "\n" << abaixo << "\n";
    return 0;
}