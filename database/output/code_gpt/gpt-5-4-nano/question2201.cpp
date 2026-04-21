/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, C;
    if (!(cin >> L)) return 0;
    cin >> C;

    long long maxSide = max(L, C);
    long long minSide = min(L, C);

    long long n = maxSide;
    long long m = minSide;

    long long a1 = n * m;
    long long k = (n + m - 2) / 2;

    if (n % 2 == 0 && m % 2 == 0) {
        long long ans1 = a1;
        long long ans2 = (n / 2) * (m / 2) + (k + 1) * (k);
        cout << ans1 << "\n" << ans2 << "\n";
    } else if (n % 2 == 1 && m % 2 == 1) {
        long long ans1 = a1 + (n + m - 2);
        long long ans2 = (n / 2) * (m / 2) + (k + 1) * (k);
        cout << ans1 << "\n" << ans2 << "\n";
    } else {
        long long ans1 = a1 + (maxSide - minSide);
        long long ans2 = (n / 2) * (m / 2) + (k + 1) * (k);
        cout << ans1 << "\n" << ans2 << "\n";
    }

    return 0;
}