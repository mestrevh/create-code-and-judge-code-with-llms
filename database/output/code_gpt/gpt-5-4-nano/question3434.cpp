/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

vector<double> lerVetor(int n) {
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}

double menorElemento(const vector<double>& v) {
    double mn = v[0];
    for (double x : v) if (x < mn) mn = x;
    return mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<double> v = lerVetor(n);
    double ans = menorElemento(v);
    cout << fixed << setprecision(10) << ans;
    return 0;
}