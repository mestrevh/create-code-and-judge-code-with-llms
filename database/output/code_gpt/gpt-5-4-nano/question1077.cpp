/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> cnt(101, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a >= 1 && a <= 100) cnt[a]++;
    }

    long long sum = 0;
    for (int v = 1; v <= 100; v++) sum += 1LL * v * cnt[v];

    int total = n;
    long long prefixSum = 0;
    int remaining = total;
    long long best = LLONG_MAX;

    vector<int> use(101, 0);

    for (int k = 1; k <= 100; k++) {
        if (cnt[k] == 0) continue;
        long long t = prefixSum + 1LL * k * (cnt[k] - 1);
        if (t > sum - t) {
            int candidate = cnt[k];
            for (int v = 1; v < k; v++) candidate += cnt[v];
            best = min(best, (long long)candidate);
        }
        prefixSum += 1LL * k * cnt[k];
        remaining -= cnt[k];
        if (prefixSum > (sum - prefixSum)) {
            int candidate = total - remaining;
            best = min(best, (long long)candidate);
            break;
        }
    }

    if (best == LLONG_MAX) {
        for (int v = 100; v >= 1; v--) {
            if (cnt[v] == 0) continue;
            break;
        }
    }

    int takeMin = (int)best;

    vector<int> csum(101, 0);
    int usedCoins = 0;
    for (int v = 1; v <= 100; v++) {
        if (csum[v] == 0) csum[v] = cnt[v];
        usedCoins += cnt[v];
    }

    long long needHigher = sum / 2 + 1;
    long long cur = 0;
    int ans = 0;
    for (int v = 100; v >= 1 && cur < needHigher; v--) {
        while (cnt[v] > 0 && cur < needHigher) {
            cur += v;
            cnt[v]--;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}