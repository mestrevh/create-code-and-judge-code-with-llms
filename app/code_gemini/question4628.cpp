/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> events;
    events.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        int chegada, partida;
        std::cin >> chegada >> partida;
        events.push_back({chegada, 1});
        events.push_back({partida, -1});
    }

    std::sort(events.begin(), events.end());

    int max_buses = 0;
    int current_buses = 0;
    for (const auto& event : events) {
        current_buses += event.second;
        if (current_buses > max_buses) {
            max_buses = current_buses;
        }
    }

    std::cout << max_buses * 20 << std::endl;

    return 0;
}
