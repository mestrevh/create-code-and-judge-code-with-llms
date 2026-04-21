/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    int K;
    cin >> K;
    vector<long long> M(K);
    long long hi = 0;
    for (int i = 0; i < K; i++) {
        cin >> M[i];
        hi = max(hi, M[i]);
    }

    long long lo = 1, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long cnt = 0;
        for (long long x : M) {
            cnt += x / mid;
            if (cnt >= N) break;
        }
        if (cnt >= N) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}