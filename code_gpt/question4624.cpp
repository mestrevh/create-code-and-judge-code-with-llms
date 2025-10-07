/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::vector<double> precos(7);
    for (int i = 0; i < 7; ++i) {
        std::cin >> precos[i];
    }
    std::cout << "[";
    for (int i = 0; i < 7; ++i) {
        std::cout << std::fixed << std::setprecision(1) << precos[i];
        if (i < 6)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
