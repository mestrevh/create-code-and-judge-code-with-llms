/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b;
    if (std::cin >> a >> b) {
        double produto = a * b;
        double razao = a / b;

        std::cout << "Produto: " << std::fixed << std::setprecision(4) << produto << "\n";
        std::cout << "Razao: " << std::fixed << std::setprecision(4) << razao << "\n";
    }

    return 0;
}