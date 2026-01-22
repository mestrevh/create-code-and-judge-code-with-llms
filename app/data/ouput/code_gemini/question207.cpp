/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    long long min_total_time = -1;
    int winner_index = 0;
    for (int i = 1; i <= n; ++i) {
        long long current_total_time = 0;
        for (int j = 0; j < m; ++j) {
            int lap_time;
            std::cin >> lap_time;
            current_total_time += lap_time;
        }
        if (min_total_time == -1 || current_total_time < min_total_time) {
            min_total_time = current_total_time;
            winner_index = i;
        }
    }
    std::cout << winner_index << std::endl;
    return 0;
}
