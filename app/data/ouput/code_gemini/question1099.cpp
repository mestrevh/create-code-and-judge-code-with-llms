/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double b_menor, b_maior, altura;
    std::cin >> b_menor >> b_maior >> altura;
    double area = ((b_menor + b_maior) * altura) / 2.0;
    std::cout << std::fixed << std::setprecision(1) << area << std::endl;
    return 0;
}
