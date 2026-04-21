/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> houses(N);
    unordered_map<int, int> pos;
    pos.reserve(N * 2);

    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
        pos[houses[i]] = i;
    }

    long long ans = 0;
    int cur = 0;

    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        int p = pos[x];
        ans += llabs((long long)p - cur);
        cur = p;
    }

    cout << ans << '\n';
    return 0;
}