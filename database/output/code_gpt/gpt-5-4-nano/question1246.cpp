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
        long long K;
        cin >> K;
        long long a = K * (K - 1) / 2;
        long long b = K * (K + 1) / 2;
        long long ans = (a + b) * K / 2;
        cout << ans << "\n";
    }
    return 0;
}