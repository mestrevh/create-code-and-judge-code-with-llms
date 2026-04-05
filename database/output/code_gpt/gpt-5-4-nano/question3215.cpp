/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<long long> T(M);
    for (int i = 0; i < M; i++) cin >> T[i];

    long long lo = 0, hi = 0;
    for (int i = 0; i < M; i++) {
        lo = max(lo, T[i]);
        hi += T[i];
    }

    auto can = [&](long long timeLimit) -> bool {
        int used = 1;
        long long sum = 0;
        for (int i = 0; i < M; i++) {
            if (sum + T[i] <= timeLimit) {
                sum += T[i];
            } else {
                used++;
                if (used > N) return false;
                sum = T[i];
            }
        }
        return true;
    };

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (can(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}