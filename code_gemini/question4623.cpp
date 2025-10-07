/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "Nenhuma nota informada!" << std::endl;
        return 0;
    }

    std::vector<double> notas(n);
    double soma = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
        soma += notas[i];
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "[";
    for (int i = 0; i < n; ++i) {
        std::cout << notas[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << soma << std::endl;

    return 0;
}
