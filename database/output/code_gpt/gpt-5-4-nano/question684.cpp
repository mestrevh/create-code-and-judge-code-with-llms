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
    vector<long long> houses(N);
    for (int i = 0; i < N; i++) cin >> houses[i];

    vector<long long> deliveries(M);
    for (int i = 0; i < M; i++) cin >> deliveries[i];

    unordered_map<long long, long long> pos;
    pos.reserve(N * 2);
    pos.max_load_factor(0.7f);
    for (int i = 0; i < N; i++) pos[houses[i]] = i;

    long long start = houses.front();
    long long currentPos = pos[start];
    long long totalTime = 0;

    if (M > 0) {
        for (int i = 0; i < M; i++) {
            long long targetPos = pos[deliveries[i]];
            totalTime += llabs(targetPos - currentPos);
            currentPos = targetPos;
        }
        if (M == 1 && deliveries[0] == start) totalTime = 0;
    }

    cout << totalTime << "\n";
    return 0;
}