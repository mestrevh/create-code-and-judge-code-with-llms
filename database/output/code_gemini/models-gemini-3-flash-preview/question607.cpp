/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Shop {
    long long s;
    int c;
};

long long tree[400040];

void update(int v, int tl, int tr, int l, int r, long long val) {
    if (l > r) return;
    if (l == tl && r == tr) {
        if (val < tree[v]) tree[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}

long long query(int v, int tl, int tr, int pos) {
    long long res = tree[v];
    if (tl == tr) return res;
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        long long q = query(2 * v, tl, tm, pos);
        if (q < res) res = q;
    } else {
        long long q = query(2 * v + 1, tm + 1, tr, pos);
        if (q < res) res = q;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> p(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int e;
        cin >> e;
        p[i] = p[i - 1] + (long long)e;
    }

    vector<vector<Shop>> shops(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, c;
        long long s;
        cin >> l >> s >> c;
        if (l >= 1 && l <= n) {
            shops[l].push_back({s, c});
        }
    }

    for (int i = 0; i < 400040; ++i) {
        tree[i] = INF;
    }

    update(1, 1, n + 1, 1, 1, 0);

    for (int i = 1; i <= n; ++i) {
        long long cur_dp = query(1, 1, n + 1, i);
        if (cur_dp >= INF) continue;

        for (const auto& shop : shops[i]) {
            long long target = shop.s + p[i - 1];
            auto it = upper_bound(p.begin(), p.end(), target);
            int k = (int)(it - p.begin()) - 1;
            if (k >= i) {
                update(1, 1, n + 1, i + 1, k + 1, cur_dp + (long long)shop.c);
            }
        }
    }

    long long ans = query(1, 1, n + 1, n + 1);
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}