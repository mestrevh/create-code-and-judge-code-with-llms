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
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int p, n;
    int case_num = 1;
    while (std::cin >> p >> n) {
        parent.resize(p);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(p, 1);

        for (int i = 0; i < n; ++i) {
            int u, v;
            std::cin >> u >> v;
            if (u < p && v < p) {
                unite_sets(u, v);
            }
        }

        int distinct_categories = 0;
        int max_size = 0;

        if (p > 0) {
            for (int i = 0; i < p; ++i) {
                if (parent[i] == i) {
                    distinct_categories++;
                    if (sz[i] > max_size) {
                        max_size = sz[i];
                    }
                }
            }
        }

        std::cout << "caso " << case_num << ": " << distinct_categories << " " << max_size << std::endl;
        case_num++;
    }

    return 0;
}
