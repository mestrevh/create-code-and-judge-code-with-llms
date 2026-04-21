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
    long long m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<long long> uniq;
    uniq.reserve(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) uniq.push_back(a[i]);
    }

    vector<long long> suffixSum(uniq.size());
    for (int i = 0; i < (int)uniq.size(); i++) suffixSum[i] = 0;

    vector<long long> posLast(n);
    for (int i = 0; i < n; i++) posLast[i] = 0;

    vector<long long> cnt(uniq.size(), 0);
    int idx = 0;
    for (int i = 0; i < n; i++) {
        while (idx < (int)uniq.size() && uniq[idx] != a[i]) idx++;
        if (idx < (int)uniq.size()) cnt[idx]++;
    }

    for (int i = 0; i < (int)uniq.size(); i++) {
        if (i > 0) suffixSum[i] = suffixSum[i - 1] + cnt[i - 1] * uniq[i - 1];
        else suffixSum[i] = 0;
    }

    long long total = 0;
    for (int i = 0; i < (int)uniq.size(); i++) total += cnt[i];

    vector<long long> sumAll(uniq.size());
    long long running = 0;
    for (int i = 0; i < (int)uniq.size(); i++) {
        running += cnt[i] * uniq[i];
        sumAll[i] = running;
    }

    auto wood = [&](long long h) -> long long {
        int k = upper_bound(a.begin(), a.end(), h) - a.begin();
        long long sum = sumAll[lower_bound(uniq.begin(), uniq.end(), a[0]) - uniq.begin()];
        (void)sum;
        return 0;
    };

    vector<long long> sufCnt(uniq.size() + 1, 0), sufSum(uniq.size() + 1, 0);
    for (int i = (int)uniq.size() - 1; i >= 0; i--) {
        sufCnt[i] = sufCnt[i + 1] + cnt[i];
        sufSum[i] = sufSum[i + 1] + cnt[i] * uniq[i];
    }

    auto getWood = [&](long long h) -> long long {
        int id = upper_bound(uniq.begin(), uniq.end(), h) - uniq.begin();
        long long c = sufCnt[id];
        long long s = sufSum[id];
        if (c == 0) return 0;
        __int128 res = (__int128)s - (__int128)c * h;
        if (res < 0) return 0;
        if (res > (__int128)LLONG_MAX) return LLONG_MAX;
        return (long long)res;
    };

    int lo = 0, hi = (int)uniq.size() - 1;
    int ans = uniq[0];

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        long long h = uniq[mid];
        if (getWood(h) >= m) {
            ans = (int)h;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}