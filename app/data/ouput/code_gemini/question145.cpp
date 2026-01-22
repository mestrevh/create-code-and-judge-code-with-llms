/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C, N;
    std::cin >> C >> N;

    std::vector<int> cashiers(C, 0);
    int delayed_clients = 0;

    for (int i = 0; i < N; ++i) {
        int T, D;
        std::cin >> T >> D;

        auto it = std::min_element(cashiers.begin(), cashiers.end());
        int earliest_free_time = *it;
        
        int start_time = std::max(T, earliest_free_time);

        if (start_time - T > 20) {
            delayed_clients++;
        }
        
        *it = start_time + D;
    }

    std::cout << delayed_clients << std::endl;

    return 0;
}
