/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    if (!(cin >> X)) return 0;

    vector<long long> a(X);
    for (int i = 0; i < X; i++) cin >> a[i];

    long long total = 0;
    for (int i = 0; i < X; i++) total += a[i];

    auto kadaneMax = [&]() -> long long {
        long long best = a[0], cur = a[0];
        for (int i = 1; i < X; i++) {
            cur = max(a[i], cur + a[i]);
            best = max(best, cur);
        }
        return best;
    };

    auto kadaneMin = [&]() -> long long {
        long long best = a[0], cur = a[0];
        for (int i = 1; i < X; i++) {
            cur = min(a[i], cur + a[i]);
            best = min(best, cur);
        }
        return best;
    };

    long long maxNonWrap = kadaneMax();
    long long minSub = kadaneMin();

    long long ans;
    if (minSub == total) ans = maxNonWrap;
    else ans = max(maxNonWrap, total - minSub);

    cout << ans << "\n";
    return 0;
}