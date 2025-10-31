/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
    }
    long long total_cost = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        total_cost += std::min(t[u], t[v]);
    }
    std::cout << total_cost << '\n';
    return 0;
}
