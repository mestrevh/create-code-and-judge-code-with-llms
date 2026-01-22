/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> dest;
std::vector<int> ans;
std::vector<int> visited;
std::vector<int> path;

void solve(int u) {
    visited[u] = 1;
    path.push_back(u);

    int v = dest[u];

    if (visited[v] == 0) {
        solve(v);
    } else if (visited[v] == 1) {
        int max_in_cycle = 0;
        size_t cycle_start_index = 0;
        for (size_t i = 0; i < path.size(); ++i) {
            if (path[i] == v) {
                cycle_start_index = i;
                break;
            }
        }
        for (size_t i = cycle_start_index; i < path.size(); ++i) {
            max_in_cycle = std::max(max_in_cycle, path[i]);
        }
        for (size_t i = cycle_start_index; i < path.size(); ++i) {
            ans[path[i]] = max_in_cycle;
        }
    }

    if (ans[u] == 0) {
        ans[u] = std::max(u, ans[v]);
    }

    path.pop_back();
    visited[u] = 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    dest.resize(n + 1);
    ans.resize(n + 1, 0);
    visited.resize(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> dest[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            solve(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}
