/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N)) return 0;
    cin >> K;
    vector<long long> M(K);
    long long maxM = 0;
    for (int i = 0; i < K; i++) {
        cin >> M[i];
        maxM = max(maxM, M[i]);
    }

    auto can = [&](long long x) -> bool {
        if (x <= 0) return true;
        long long cnt = 0;
        for (long long len : M) {
            cnt += len / x;
            if (cnt >= N) return true;
        }
        return cnt >= N;
    };

    long long lo = 1, hi = maxM, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}