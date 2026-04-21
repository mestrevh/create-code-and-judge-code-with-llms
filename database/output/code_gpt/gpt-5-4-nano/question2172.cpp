/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long sumDistances(const vector<int>& perm, int keyIndex, int N) {
    if (N <= 1) return 0;
    vector<int> vis(N, 0);
    long long dist = 0;
    int cur = perm[0];
    vis[cur] = 1;
    for (int i = 1; i < N; i++) {
        int nxt = perm[i];
        if (nxt == -1) nxt = keyIndex;
        dist += 1;
        if (vis[nxt]) return -1;
        vis[nxt] = 1;
        cur = nxt;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int posKey = -1;
    for (int i = 0; i < N; i++) {
        if (a[i] == -1) posKey = i;
    }

    long long total = 0;
    long long stepsToKey = posKey;
    long long stepsBack = posKey;
    total = stepsToKey + stepsBack;

    cout << total << "\n";
    return 0;
}