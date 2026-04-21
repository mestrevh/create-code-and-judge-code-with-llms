/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double side;
    if (std::cin >> side) {
        double area = side * side;
        double doubleArea = area * 2.0;

        std::cout << "Informe a medida de um dos lados do quadrado:\n";
        std::cout << "Resultado: " << std::fixed << std::setprecision(1) << area << "\n";
        std::cout << "Dobro: " << std::fixed << std::setprecision(1) << doubleArea << "\n";
    }

    return 0;
}