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

    int x, y, n;
    std::cin >> x >> y >> n;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int referrer;
        std::cin >> referrer;
        adj[referrer].push_back(i);
    }

    std::vector<int> day_subscribed(n + 1, 0);
    std::queue<int> q;

    for (int person : adj[0]) {
        day_subscribed[person] = 1;
        q.push(person);
    }

    int total_subs = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (day_subscribed[u] <= y) {
            total_subs++;
        }

        if (day_subscribed[u] >= y) {
            continue;
        }

        for (int v : adj[u]) {
            if (day_subscribed[v] == 0) {
                day_subscribed[v] = day_subscribed[u] + 1;
                q.push(v);
            }
        }
    }

    if (total_subs >= x) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}
