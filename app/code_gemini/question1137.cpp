/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

using ll = long long;
using state_t = std::vector<int>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    state_t initial_state(8);
    state_t final_state(8);

    for (int i = 0; i < 8; ++i) {
        std::cin >> initial_state[i];
    }

    for (int i = 0; i < 8; ++i) {
        std::cin >> final_state[i];
    }

    std::priority_queue<std::pair<ll, state_t>,
                        std::vector<std::pair<ll, state_t>>,
                        std::greater<std::pair<ll, state_t>>> pq;

    std::map<state_t, ll> dist;

    dist[initial_state] = 0;
    pq.push({0, initial_state});

    while (!pq.empty()) {
        ll current_cost = pq.top().first;
        state_t current_state = pq.top().second;
        pq.pop();

        auto it = dist.find(current_state);
        if (it != dist.end() && current_cost > it->second) {
            continue;
        }

        if (current_state == final_state) {
            std::cout << current_cost << std::endl;
            return 0;
        }

        for (int i = 0; i < 8; ++i) {
            if ((i % 4) != 3) {
                state_t next_state = current_state;
                std::swap(next_state[i], next_state[i + 1]);
                ll move_cost = current_state[i] + current_state[i + 1];
                ll new_cost = current_cost + move_cost;

                auto it_next = dist.find(next_state);
                if (it_next == dist.end() || new_cost < it_next->second) {
                    dist[next_state] = new_cost;
                    pq.push({new_cost, next_state});
                }
            }
        }

        for (int i = 0; i < 4; ++i) {
            state_t next_state = current_state;
            std::swap(next_state[i], next_state[i + 4]);
            ll move_cost = current_state[i] + current_state[i + 4];
            ll new_cost = current_cost + move_cost;

            auto it_next = dist.find(next_state);
            if (it_next == dist.end() || new_cost < it_next->second) {
                dist[next_state] = new_cost;
                pq.push({new_cost, next_state});
            }
        }
    }

    return 0;
}
