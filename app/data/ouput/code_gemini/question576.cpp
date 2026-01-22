/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while (std::cin >> n && n != 0) {
        int e;
        std::cin >> e;

        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < e; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::vector<int> color(n, 0);
        std::queue<int> q;
        bool is_bipartite = true;

        q.push(0);
        color[0] = 1;

        while (!q.empty() && is_bipartite) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = 3 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    is_bipartite = false;
                    break;
                }
            }
        }

        if (is_bipartite) {
            std::cout << "BICOLORABLE.\n";
        } else {
            std::cout << "NOT BICOLORABLE.\n";
        }
    }

    return 0;
}
