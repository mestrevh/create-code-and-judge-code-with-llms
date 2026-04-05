/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, r;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        p.resize(n + 1);
        r.assign(n + 1, 0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        p[x] = find(p[x]);
        return p[x];
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    DSU dsu(N);
    for (int k = 0; k < M; k++) {
        int i, j;
        cin >> i >> j;
        dsu.unite(i, j);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) if (dsu.find(i) == i) ans++;
    cout << ans << "\n";
    return 0;
}