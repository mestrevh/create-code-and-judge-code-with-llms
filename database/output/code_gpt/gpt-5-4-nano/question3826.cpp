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
    if (!(cin >> x)) return 0;
    long long ans = x + 1;
    if (ans < 0) ans = 0;
    cout << ans << "\n";
    return 0;
}