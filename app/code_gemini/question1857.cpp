/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

const int MAXN = 100005;
const int BITS = 31;

std::vector<int> adj[MAXN];
int n;
long long initial_values[MAXN];
int tin[MAXN], tout[MAXN], timer;
int vertex_at_time[MAXN];
long long flat_initial_values[MAXN];

void dfs(int u, int p) {
    tin[u] = ++timer;
    vertex_at_time[timer] = u;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}

struct SegTree {
    std::vector<int> count;
    std::vector<bool> lazy;
    int size;

    void init(int n) {
        size = n;
        count.assign(4 * size + 5, 0);
        lazy.assign(4 * size + 5, false);
    }

    void push(int v, int tl, int tr) {
        if (lazy[v]) {
            count[v] = (tr - tl + 1) - count[v];
            if (tl != tr) {
                lazy[2 * v] = !lazy[2 * v];
                lazy[2 * v + 1] = !lazy[2 * v + 1];
            }
            lazy[v] = false;
        }
    }
    
    void build(const std::vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            if (tl < a.size()) {
                count[v] = a[tl];
            }
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            count[v] = count[2 * v] + count[2 * v + 1];
        }
    }
    
    void update(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > tr || r < tl) {
            return;
        }
        if (l <= tl && tr <= r) {
            lazy[v] = !lazy[v];
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r);
        update(2 * v + 1, tm + 1, tr, l, r);
        count[v] = count[2 * v] + count[2 * v + 1];
    }
    
    int query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) {
            return 0;
        }
        push(v, tl, tr);
        if (l <= tl && tr <= r) {
            return count[v];
        }
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm + 1, tr, l, r);
    }
};

SegTree seg_trees[BITS];

int main() {
    fast_io();

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> initial_values[i];
    }
    
    timer = 0;
    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        flat_initial_values[i] = initial_values[vertex_at_time[i]];
    }

    for (int b = 0; b < BITS; ++b) {
        std::vector<int> bit_array(n + 1);
        for (int i = 1; i <= n; ++i) {
            if ((flat_initial_values[i] >> b) & 1) {
                bit_array[i] = 1;
            } else {
                bit_array[i] = 0;
            }
        }
        seg_trees[b].init(n);
        seg_trees[b].build(bit_array, 1, 1, n);
    }
    
    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int v, k;
            std::cin >> v >> k;
            int l = tin[v];
            int r = tout[v];
            for (int b = 0; b < BITS; ++b) {
                if ((k >> b) & 1) {
                    seg_trees[b].update(1, 1, n, l, r);
                }
            }
        } else {
            int v;
            std::cin >> v;
            int l = tin[v];
            int r = tout[v];
            long long total_sum = 0;
            for (int b = 0; b < BITS; ++b) {
                long long count_ones = seg_trees[b].query(1, 1, n, l, r);
                total_sum += count_ones * (1LL << b);
            }
            std::cout << total_sum << "\n";
        }
    }

    return 0;
}
