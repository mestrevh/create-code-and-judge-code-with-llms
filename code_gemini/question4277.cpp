/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double base_maior, base_menor, altura;

    std::cin >> base_maior;
    std::cin >> base_menor;
    std::cin >> altura;

    double area = ((base_maior + base_menor) * altura) / 2.0;

    std::cout << std::fixed << std::setprecision(15) << area << std::endl;

    return 0;
}
