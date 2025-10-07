/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double angulo1, angulo2;
    std::cout << "Digite o 1° ângulo:\n";
    std::cin >> angulo1;
    std::cout << "Digite o 2° ângulo:\n";
    std::cin >> angulo2;
    double angulo3 = 180.0 - angulo1 - angulo2;
    std::cout << "O terceiro ângulo é: " << std::fixed << std::setprecision(1) << angulo3 << std::endl;
    return 0;
}
