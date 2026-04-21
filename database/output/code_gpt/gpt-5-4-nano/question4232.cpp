/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    long long g = 0;
    while (cin >> x) {
        if (x <= 0) break;
        g = (g == 0) ? x : std::gcd(g, x);
    }
    if (g == 0) g = 0;
    cout << g << "\n";
    return 0;
}