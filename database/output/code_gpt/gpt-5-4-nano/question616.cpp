/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int ans = 0;
    ans += (A == T);
    ans += (B == T);
    ans += (C == T);
    ans += (D == T);
    ans += (E == T);

    cout << ans << "\n";
    return 0;
}