/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using ll = long long;
const ll INF = 1e18;

namespace MaxFlow {
    struct Edge {
        int to;
        ll cap;
        int rev;
    };

    std::vector<std::vector<Edge>> adj;
    std::vector<int> level;
    std::vector<int> iter;

    void init(int n) {
        adj.assign(n, std::vector<Edge>());
        level.resize(n);
        iter.resize(n);
    }

    void add_edge(int from, int to, ll cap) {
        adj[from].push_back({to, cap, (int)adj[to].size()});
        adj[to].push_back({from, 0, (int)adj[from].size() - 1});
    }

    bool bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const auto& edge : adj[v]) {
                if (edge.cap > 0 && level[edge.to] < 0) {
                    level[edge.to] = level[v] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, int t, ll f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < adj[v].size(); ++i) {
            Edge& e = adj[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                ll d = dfs(e.to, t, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    adj[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll solve(int s, int t) {
        ll flow = 0;
        while (bfs(s, t)) {
            std::fill(iter.begin(), iter.end(), 0);
            ll f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
}

struct Card {
    ll health, power;
    std::vector<int> attackable;
};

ll calculate_turns(int n, const std::vector<Card>& attacker, const std::vector<Card>& defender) {
    ll total_health = 0;
    for (const auto& card : defender) {
        total_health += card.health;
    }
    if (total_health == 0) return 0;

    int num_nodes = 2 * n + 2;
    int source = 2 * n;
    int sink = 2 * n + 1;

    MaxFlow::init(num_nodes);

    for (int i = 0; i < n; ++i) {
        MaxFlow::add_edge(source, i, attacker[i].power);
    }

    for (int i = 0; i < n; ++i) {
        for (int target_idx : attacker[i].attackable) {
            MaxFlow::add_edge(i, n + target_idx, INF);
        }
    }

    for (int j = 0; j < n; ++j) {
        MaxFlow::add_edge(n + j, sink, defender[j].health);
    }
    
    ll max_damage_per_turn = MaxFlow::solve(source, sink);

    if (max_damage_per_turn == 0) {
        return -1;
    }

    return (total_health + max_damage_per_turn - 1) / max_damage_per_turn;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Card> entity_cards(n);
    std::vector<Card> x_cards(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> entity_cards[i].health >> entity_cards[i].power;
        int k;
        std::cin >> k;
        entity_cards[i].attackable.resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> entity_cards[i].attackable[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> x_cards[i].health >> x_cards[i].power;
        int k;
        std::cin >> k;
        x_cards[i].attackable.resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> x_cards[i].attackable[j];
        }
    }

    ll entity_turns = calculate_turns(n, entity_cards, x_cards);
    ll x_turns = calculate_turns(n, x_cards, entity_cards);

    if (entity_turns == -1) {
        std::cout << "X wins in " << x_turns << " turns\n";
    } else if (x_turns == -1) {
        std::cout << "Entity wins in " << entity_turns << " turns\n";
    } else {
        if (entity_turns <= x_turns) {
            std::cout << "Entity wins in " << entity_turns << " turns\n";
        } else {
            std::cout << "X wins in " << x_turns << " turns\n";
        }
    }

    return 0;
}
