/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int hamburguer, cheeseburger, fritas, refrigerante, milkshake;

    std::cin >> hamburguer;
    std::cin >> cheeseburger;
    std::cin >> fritas;
    std::cin >> refrigerante;
    std::cin >> milkshake;

    double total = 0.0;

    total += hamburguer * 3.00;
    total += cheeseburger * 2.50;
    total += fritas * 2.50;
    total += refrigerante * 1.00;
    total += milkshake * 3.00;

    std::cout << "conta final: " << std::fixed << std::setprecision(1) << total << std::endl;

    return 0;
}
