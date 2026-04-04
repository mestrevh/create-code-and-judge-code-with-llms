/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> prices(7);
    for (int i = 0; i < 7; ++i) {
        if (!(std::cin >> prices[i])) break;
    }

    std::cout << "[";
    for (int i = 0; i < 7; ++i) {
        std::cout << std::fixed << std::setprecision(1) << prices[i];
        if (i < 6) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}