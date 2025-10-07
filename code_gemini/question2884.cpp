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

    std::cout << "Digite a sequencia de numero:\n";
    std::cout << "Indice no qual o numero desejado aparece:\n";

    std::vector<double> numbers(100);
    for (int i = 0; i < 100; ++i) {
        std::cin >> numbers[i];
    }

    double target;
    std::cin >> target;

    for (int i = 0; i < 100; ++i) {
        if (numbers[i] == target) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
