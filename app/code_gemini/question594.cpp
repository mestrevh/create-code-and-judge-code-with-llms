/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> parent(n + 1);
    std::iota(parent.begin() + 1, parent.end(), 1);

    std::function<int(int)> find_set = 
        [&](int v) -> int {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    };

    auto unite_sets = [&](int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
        }
    };

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        unite_sets(u, v);
    }

    std::vector<long long> team_bananas(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long current_monkey_bananas;
        std::cin >> current_monkey_bananas;
        team_bananas[find_set(i)] += current_monkey_bananas;
    }

    long long max_bananas = 0;
    for (int i = 1; i <= n; ++i) {
        max_bananas = std::max(max_bananas, team_bananas[i]);
    }
    
    std::cout << max_bananas << "\n";
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
