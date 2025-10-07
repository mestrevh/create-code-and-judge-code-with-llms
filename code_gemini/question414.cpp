/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void solve() {
    int m;
    std::cin >> m;
    std::vector<int> initial_queue(m);
    std::vector<int> sorted_queue(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> initial_queue[i];
    }

    sorted_queue = initial_queue;

    std::sort(sorted_queue.begin(), sorted_queue.end(), std::greater<int>());

    int unchanged_count = 0;
    for (int i = 0; i < m; ++i) {
        if (initial_queue[i] == sorted_queue[i]) {
            unchanged_count++;
        }
    }
    std::cout << unchanged_count << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}
