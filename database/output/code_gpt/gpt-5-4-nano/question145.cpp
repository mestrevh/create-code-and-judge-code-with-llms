/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N;
    if (!(cin >> C >> N)) return 0;

    vector<long long> finish(C, 0);
    for (int i = 0; i < C; i++) finish[i] = 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < C; i++) pq.push(0);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        long long T, D;
        cin >> T >> D;

        long long earliest = pq.top();
        pq.pop();

        long long start = max(T, earliest);
        if (start - T > 20) ans++;

        long long newFinish = start + D;
        pq.push(newFinish);
    }

    cout << ans << "\n";
    return 0;
}