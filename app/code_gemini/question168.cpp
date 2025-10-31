/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double recipes[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> recipes[i][j];
        }
    }

    double prices[4];
    for (int i = 0; i < 4; ++i) {
        std::cin >> prices[i];
    }

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < 3; ++i) {
        double cost = 0.0;
        for (int j = 0; j < 4; ++j) {
            cost += recipes[i][j] * prices[j];
        }
        std::cout << cost << std::endl;
    }

    return 0;
}
