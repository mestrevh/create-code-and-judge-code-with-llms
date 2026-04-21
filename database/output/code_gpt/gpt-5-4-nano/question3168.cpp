/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;
    long long ans = (c > a) ? 2 * a : 3 * b;
    cout << ans << "\n";
    return 0;
}