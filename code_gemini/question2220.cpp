/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;

    std::string colors[4] = {"Verde", "Vermelho", "Azul", "Amarelo"};
    int prices[4];
    int velocities[4];
    double cost_benefits[4];

    for (int i = 0; i < 4; ++i) {
        std::cin >> prices[i] >> velocities[i];
    }

    double max_cb = -1.0;
    bool any_affordable = false;

    for (int i = 0; i < 4; ++i) {
        if (prices[i] <= m) {
            any_affordable = true;
            cost_benefits[i] = static_cast<double>(velocities[i]) / prices[i];
            if (cost_benefits[i] > max_cb) {
                max_cb = cost_benefits[i];
            }
        } else {
            cost_benefits[i] = -1.0; 
        }
    }

    if (!any_affordable) {
        std::cout << "Acho que vou a pé :( " << std::endl;
        return 0;
    }

    if (prices[0] <= m) {
        if (max_cb - cost_benefits[0] <= 1.0) {
            std::cout << "Verde" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (prices[i] <= m && cost_benefits[i] == max_cb) {
            std::cout << colors[i] << std::endl;
            return 0;
        }
    }

    return 0;
}
