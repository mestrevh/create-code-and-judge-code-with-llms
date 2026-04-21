/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long L, C, H, l, c, h;
    if (!(cin >> L >> C >> H >> l >> c >> h)) return 0;

    bool ok = false;
    if (l <= L && c <= C && h <= H) ok = true;
    if (c <= L && l <= C && h <= H) ok = true;

    cout << (ok ? "SIM" : "NAO") << "\n";
    return 0;
}