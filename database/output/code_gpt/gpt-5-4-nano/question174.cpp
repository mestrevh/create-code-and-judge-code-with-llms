/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;

    long long ans = 7;
    long long cur = N;

    if (cur > 10) {
        long long x = cur - 10;
        while (x > 0) {
            long long add;
            if (x <= 0) break;

            long long a = min(x, 20LL);
            ans += a * 1;

            x -= a;
            if (x <= 0) break;

            a = min(x, 70LL);
            ans += a * 2;

            x -= a;
            if (x <= 0) break;

            a = x;
            ans += a * 1;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}