/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int S, T, F;
    if (!(cin >> S >> T >> F)) return 0;
    int ans = (S + T + F) % 24;
    if (ans < 0) ans += 24;
    cout << ans;
    return 0;
}