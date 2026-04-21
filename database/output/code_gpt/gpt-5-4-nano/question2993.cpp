/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, n;
    if (!(cin >> x >> n)) return 0;

    long long y = (n - 1) / x;
    cout << "O numero " << x << " tem " << y << " multiplos menores que " << n << ".";
    return 0;
}