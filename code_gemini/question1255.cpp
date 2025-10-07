/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <tuple>
#include <algorithm>

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    if (b == 1) return a;
    
    long long res = a / gcd(a, b);
    
    // Check for potential overflow before multiplication
    // Using a sufficiently large constant for the cap
    if (b > 200000 / res) {
        return 200001; 
    }
    
    res *= b;
    if (res > 200000) return 200001; // Cap to prevent excessive memory usage
    return res;
}

const long long INF = -1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, e, s, m;
    std::cin >> n >> e >> s >> m;

    std::vector<int> p(n);
    std::set<int> periods_set;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        // p[i] + 1 is the cycle length
        if (p[i] + 1 > 1) {
            periods_set.insert(p[i] + 1);
        }
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }

    // A monster with period 0 attacks at time 0, 1, 2, ...
    // This is because t % (0+1) == 0.
    // However, the problem states the first attack is after the recovery period P.
    // So for P=0, the first attack is at t=0.
    if ((0 % (p[e] + 1)) == p[e]) {
        std::cout << "Araragi morreu\n";
        return 0;
    }

    long long L = 1;
    for (int val : periods_set) {
        L = lcm(L, val);
    }
    
    std::vector<std::vector<long long>> dist(n, std::vector<long long>(L, INF));
    
    using State = std::tuple<long long, int, int>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    dist[e][0] = 0;
    pq.push({0, e, 0});

    while (!pq.empty()) {
        auto [time, u, time_mod_L] = pq.top();
        pq.pop();

        if (u == s) {
            std::cout << time << " minutos\n";
            return 0;
        }

        if (dist[u][time_mod_L] != INF && time > dist[u][time_mod_L]) {
            continue;
        }

        long long next_time = time + 1;
        int next_time_mod_L = (int)(next_time % L);

        // Try to move to neighbors
        for (int v : adj[u]) {
            bool is_safe = (next_time % (p[v] + 1)) != p[v];
            if (is_safe) {
                if (dist[v][next_time_mod_L] == INF || next_time < dist[v][next_time_mod_L]) {
                    dist[v][next_time_mod_L] = next_time;
                    pq.push({next_time, v, next_time_mod_L});
                }
            }
        }

        // Try to wait
        bool is_safe_to_wait = (next_time % (p[u] + 1)) != p[u];
        if (is_safe_to_wait) {
            if (dist[u][next_time_mod_L] == INF || next_time < dist[u][next_time_mod_L]) {
                dist[u][next_time_mod_L] = next_time;
                pq.push({next_time, u, next_time_mod_L});
            }
        }
    }

    std::cout << "Araragi morreu\n";

    return 0;
}
