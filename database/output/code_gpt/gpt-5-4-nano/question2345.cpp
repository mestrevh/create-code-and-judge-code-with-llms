/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void verificaRetangulo(long long a, long long b, long long c, long long d) {
    vector<long long> v = {a, b, c, d};
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[2] == v[3] && v[0] > 0 && v[2] > 0) cout << "formam um retangulo";
    else cout << "nao formam um retangulo";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;
    verificaRetangulo(a, b, c, d);
    return 0;
}