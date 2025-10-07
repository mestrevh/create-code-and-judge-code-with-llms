/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

std::vector<int> parent;
std::vector<int> sz;

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            std::swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    parent.assign(n + 1, 0);
    std::iota(parent.begin(), parent.end(), 0);
    sz.assign(n + 1, 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        unite_sets(u, v);
    }

    int max_size = 0;
    if (n > 0) {
        max_size = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (sz[i] > max_size) {
            max_size = sz[i];
        }
    }
    std::cout << max_size << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
