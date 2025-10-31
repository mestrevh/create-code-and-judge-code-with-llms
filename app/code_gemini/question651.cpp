/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const long long INF = 0x3f3f3f3f3f3f3f3fLL;
    const int MAX_HP_DMG = 2001;

    int M, N, G, K;
    while (std::cin >> M >> N >> G >> K && (M || N || G || K)) {
        
        std::vector<std::pair<int, int>> spells(M);
        for (int i = 0; i < M; ++i) {
            std::cin >> spells[i].first >> spells[i].second;
        }

        std::vector<long long> dp_damage(MAX_HP_DMG, INF);
        dp_damage[0] = 0;

        for (const auto& spell : spells) {
            int cost = spell.first;
            int damage = spell.second;
            if (damage <= 0) continue;
            for (int d = damage; d < MAX_HP_DMG; ++d) {
                if (dp_damage[d - damage] != INF) {
                    dp_damage[d] = std::min(dp_damage[d], dp_damage[d - damage] + cost);
                }
            }
        }

        std::vector<long long> min_mana(MAX_HP_DMG, INF);
        min_mana[MAX_HP_DMG - 1] = dp_damage[MAX_HP_DMG - 1];
        for (int h = MAX_HP_DMG - 2; h >= 1; --h) {
            min_mana[h] = std::min(min_mana[h + 1], dp_damage[h]);
        }

        std::vector<std::vector<int>> adj(N + 1);
        for (int i = 0; i < G; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::vector<long long> salon_cost(N + 1, 0);
        for (int i = 0; i < K; ++i) {
            int s, hp;
            std::cin >> s >> hp;
            if (hp <= 0) continue;

            long long cost_to_kill = min_mana[hp];
            
            if (cost_to_kill == INF) {
                salon_cost[s] = INF;
            } else if (salon_cost[s] != INF) {
                salon_cost[s] += cost_to_kill;
            }
        }

        std::vector<long long> dist(N + 1, INF);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;

        dist[1] = salon_cost[1];
        if (dist[1] < INF) {
            pq.push({dist[1], 1});
        }

        long long final_dist = -1;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) {
                continue;
            }
            
            if (u == N) {
                final_dist = d;
                break;
            }

            for (int v : adj[u]) {
                if (salon_cost[v] == INF) continue;
                
                long long new_cost = d + salon_cost[v];
                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.push({new_cost, v});
                }
            }
        }

        std::cout << final_dist << "\n";
    }

    return 0;
}
