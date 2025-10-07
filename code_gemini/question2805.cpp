/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int base_menor, base_maior, altura;

    std::cout << "Digite a base menor:\n";
    std::cin >> base_menor;

    std::cout << "Digite a base maior:\n";
    std::cin >> base_maior;

    std::cout << "Digite a altura:\n";
    std::cin >> altura;

    double area = ((double)(base_menor + base_maior) * altura) / 2.0;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Area do trapezio: " << area << std::endl;

    return 0;
}
