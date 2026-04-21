/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long b_menor, b_maior, altura;
    if (!(std::cin >> b_menor >> b_maior >> altura)) return 0;

    double area = static_cast<double>(b_menor + b_maior) * altura / 2.0;

    std::cout << "Digite a base menor:\n";
    std::cout << "Digite a base maior:\n";
    std::cout << "Digite a altura:\n";
    std::cout << "Area do trapezio: " << std::fixed << std::setprecision(6) << area << std::endl;

    return 0;
}