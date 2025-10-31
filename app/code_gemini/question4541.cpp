/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<double, int>> events;
    events.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        double start, end;
        std::cin >> start >> end;
        events.push_back({start, 1});
        events.push_back({end, -1});
    }

    std::sort(events.begin(), events.end());

    int max_overlap = 0;
    int current_overlap = 0;

    for (const auto& event : events) {
        current_overlap += event.second;
        if (current_overlap > max_overlap) {
            max_overlap = current_overlap;
        }
    }

    std::cout << max_overlap << std::endl;

    return 0;
}
