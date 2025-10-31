/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

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

    int n, k;
    std::cin >> n >> k;

    parent.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    sz.assign(n + 1, 1);

    char op;
    int a, b;
    for (int i = 0; i < k; ++i) {
        std::cin >> op >> a >> b;
        if (op == 'F') {
            unite_sets(a, b);
        } else {
            if (find_set(a) == find_set(b)) {
                std::cout << "S\n";
            } else {
                std::cout << "N\n";
            }
        }
    }

    return 0;
}
