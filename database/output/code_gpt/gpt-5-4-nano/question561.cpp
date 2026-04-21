/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;

    long long ans = 0;
    for (long long len = 1; ; len++) {
        long long start = (len == 1) ? 1 : (long long)pow(10.0, len - 1);
        if (start > n) break;
        long long end = min(n, (long long)pow(10.0, len) - 1);
        long long count = end - start + 1;
        if (count > 0) ans += count * len;
    }

    cout << ans << "\n";
    return 0;
}