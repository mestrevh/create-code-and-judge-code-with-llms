/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer;
int val[MAXN];
int flat[MAXN];
int tree[4 * MAXN];
bool lazy[4 * MAXN];

struct Query {
    int type, v, k, id;
};

void dfs(int u, int p) {
    tin[u] = ++timer;
    flat[timer] = val[u];
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer;
}

void build(int v, int tl, int tr, int bit) {
    lazy[v] = false;
    if (tl == tr) {
        tree[v] = (flat[tl] >> bit) & 1;
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, bit);
        build(2 * v + 1, tm + 1, tr, bit);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

void push(int v, int tl, int tr) {
    if (lazy[v]) {
        int tm = (tl + tr) / 2;
        tree[2 * v] = (tm - tl + 1) - tree[2 * v];
        lazy[2 * v] = !lazy[2 * v];
        tree[2 * v + 1] = (tr - tm) - tree[2 * v + 1];
        lazy[2 * v + 1] = !lazy[2 * v + 1];
        lazy[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r) return;
    if (l == tl && r == tr) {
        tree[v] = (tr - tl + 1) - tree[v];
        lazy[v] = !lazy[v];
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm));
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return tree[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(r, tm)) +
           query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> val[i];

    timer = 0;
    dfs(1, 0);

    int q;
    if (!(cin >> q)) return 0;
    vector<Query> queries(q);
    int q2_count = 0;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == 1) {
            cin >> queries[i].v >> queries[i].k;
            queries[i].id = -1;
        } else {
            cin >> queries[i].v;
            queries[i].id = q2_count++;
        }
    }

    vector<long long> results(q2_count, 0);
    for (int b = 0; b <= 30; ++b) {
        build(1, 1, n, b);
        for (int i = 0; i < q; ++i) {
            if (queries[i].type == 1) {
                if ((queries[i].k >> b) & 1) {
                    update(1, 1, n, tin[queries[i].v], tout[queries[i].v]);
                }
            } else {
                results[queries[i].id] += (1LL << b) * (long long)query(1, 1, n, tin[queries[i].v], tout[queries[i].v]);
            }
        }
    }

    for (int i = 0; i < q2_count; ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}