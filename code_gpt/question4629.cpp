/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> saltos(n);
    double maior = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> saltos[i];
        if (saltos[i] > maior) {
            maior = saltos[i];
        }
        std::cout << std::fixed << std::setprecision(1) << maior << std::endl;
    }

    std::sort(saltos.begin(), saltos.end());
    std::cout << "[";
    for (int i = 0; i < n; ++i) {
        std::cout << saltos[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
