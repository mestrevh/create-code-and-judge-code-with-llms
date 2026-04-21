/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n1, n2;
    while (std::cin >> n1 >> n2) {
        std::cout << "Digite um numero:\n";
        std::cout << "Digite outro numero:\n";
        std::cout << "Soma: " << std::fixed << std::setprecision(1) << (n1 + n2) << "\n";
    }

    return 0;
}