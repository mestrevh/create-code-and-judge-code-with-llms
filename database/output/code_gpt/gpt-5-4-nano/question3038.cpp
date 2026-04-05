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
    while (T--) {
        long long R1, R2;
        cin >> R1 >> R2;
        long long a = min(R1, R2);
        long long b = max(R1, R2);
        long long ans = a + b + 2 * a;
        ans = 2 * a + b;
        if (a == b) ans = 3 * a;
        cout << ans << "\n";
    }
    return 0;
}