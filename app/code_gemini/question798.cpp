/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>
#include <queue>

bool is_power_of_two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int log2_int(int n) {
    if (n <= 1) return 0;
    int count = 0;
    while ((1 << count) < n) {
        count++;
    }
    return count;
}

int count_common(const std::vector<int>& v1, const std::vector<int>& v2) {
    int common_count = 0;
    unsigned int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            i++;
        } else if (v2[j] < v1[i]) {
            j++;
        } else {
            common_count++;
            i++;
            j++;
        }
    }
    return common_count;
}

bool solve() {
    int k, m;
    std::cin >> k >> m;
    if (k == 0 && m == 0) return false;

    std::vector<std::vector<int>> adj(k);
    bool valid_input = true;

    for (int i = 0; i < m; ++i) {
        int u_in, v_in;
        std::cin >> u_in >> v_in;
        if (u_in >= k || v_in >= k || u_in < 0 || v_in < 0) {
            valid_input = false;
        }
        if (valid_input) {
            if (u_in != v_in) {
                adj[u_in].push_back(v_in);
                adj[v_in].push_back(u_in);
            }
        }
    }

    if (!valid_input) {
        std::cout << "NAO\n";
        return true;
    }

    int edge_count = 0;
    for (int i = 0; i < k; ++i) {
        std::sort(adj[i].begin(), adj[i].end());
        adj[i].erase(std::unique(adj[i].begin(), adj[i].end()), adj[i].end());
        edge_count += adj[i].size();
    }
    edge_count /= 2;

    if (!is_power_of_two(k)) {
        std::cout << "NAO\n";
        return true;
    }

    int n = log2_int(k);

    if (edge_count != (1LL * k * n) / 2) {
        std::cout << "NAO\n";
        return true;
    }

    for (int i = 0; i < k; ++i) {
        if (adj[i].size() != (size_t)n) {
            std::cout << "NAO\n";
            return true;
        }
    }

    if (k <= 1) {
        std::cout << "SIM\n";
        return true;
    }

    std::vector<int> color(k, -1);
    std::queue<int> q;
    int visited_count = 0;
    bool is_bipartite = true;

    int start_node = 0;
    if (adj[start_node].empty() && k > 1) {
        for (int i = 0; i < k; ++i) {
            if (!adj[i].empty()) {
                start_node = i;
                break;
            }
        }
    }
    
    q.push(start_node);
    color[start_node] = 0;
    visited_count = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                visited_count++;
                q.push(v);
            } else if (color[v] == color[u]) {
                is_bipartite = false;
            }
        }
    }

    if (visited_count != k || !is_bipartite) {
        std::cout << "NAO\n";
        return true;
    }

    if (n < 2) {
        std::cout << "SIM\n";
        return true;
    }

    for (int u = 0; u < k; ++u) {
        for (size_t i = 0; i < adj[u].size(); ++i) {
            for (size_t j = i + 1; j < adj[u].size(); ++j) {
                int v1 = adj[u][i];
                int v2 = adj[u][j];
                if (count_common(adj[v1], adj[v2]) != 2) {
                    std::cout << "NAO\n";
                    return true;
                }
            }
        }
    }

    std::cout << "SIM\n";
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (solve());
    return 0;
}
