/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> parent;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    parent.resize(N + 1);
    std::iota(parent.begin() + 1, parent.end(), 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        unite_sets(u, v);
    }

    int teams = 0;
    for (int i = 1; i <= N; ++i) {
        if (parent[i] == i) {
            teams++;
        }
    }

    std::cout << teams << std::endl;

    return 0;
}
