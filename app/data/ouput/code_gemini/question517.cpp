/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

struct DSU {
    std::vector<int> parent;
    std::vector<int> sz;

    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
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
};

void solve() {
    int N, M, Q;
    bool first_case = true;

    while (std::cin >> N >> M >> Q) {
        if (!first_case) {
            std::cout << "\n";
        }
        first_case = false;

        int total_cells = N * N;
        DSU dsu(total_cells);

        for (int i = 0; i < M; ++i) {
            int W;
            std::cin >> W;

            if (N <= 1) {
                continue;
            }

            int u, v;
            int walls_per_row = 2 * N - 1;
            int walls_before_last_row = (N - 1) * walls_per_row;

            if (W < walls_before_last_row) {
                int r = W / walls_per_row;
                int w_idx = W % walls_per_row;

                if (w_idx < N - 1) {
                    u = r * N + w_idx;
                    v = r * N + w_idx + 1;
                } else {
                    int h_idx = w_idx - (N - 1);
                    u = r * N + h_idx;
                    v = (r + 1) * N + h_idx;
                }
            } else {
                int r = N - 1;
                int w_idx = W - walls_before_last_row;
                u = r * N + w_idx;
                v = r * N + w_idx + 1;
            }
            dsu.union_sets(u, v);
        }

        std::vector<int> roots(total_cells);
        if (total_cells > 0) {
            for (int i = 0; i < total_cells; ++i) {
                roots[i] = dsu.find_set(i);
            }
        }

        for (int j = 1; j <= Q; ++j) {
            int A, B;
            std::cin >> A >> B;
            bool connected = (roots[A] == roots[B]);
            std::cout << j << "." << (connected ? "1" : "0") << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
