/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;

    std::vector<int> prices(4);
    std::cin >> prices[0] >> prices[1] >> prices[2] >> prices[3];

    std::vector<std::string> names = {"Verde", "Vermelho", "Roxo", "Amarelo"};
    std::vector<int> speeds = {80, 100, 120, 80};

    int best_index = -1;
    double max_cost_benefit = -1.0;

    for (int i = 0; i < 4; ++i) {
        if (prices[i] <= m) {
            double current_cost_benefit = static_cast<double>(speeds[i]) / prices[i];
            if (current_cost_benefit > max_cost_benefit) {
                max_cost_benefit = current_cost_benefit;
                best_index = i;
            }
        }
    }

    if (best_index == -1) {
        std::cout << "Acho que vou a pe :(" << '\n';
    } else {
        std::cout << names[best_index] << '\n';
    }

    return 0;
}
