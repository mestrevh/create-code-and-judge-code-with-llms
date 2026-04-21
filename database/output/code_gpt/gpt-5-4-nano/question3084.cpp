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
        long long N;
        cin >> N;
        bool ok = false;
        if (N > 0 && (N & (N - 1)) == 0) ok = true;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}