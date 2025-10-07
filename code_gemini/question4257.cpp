/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double angulo1, angulo2, angulo3;

    std::cout << "Digite o 1° ângulo:" << std::endl;
    std::cin >> angulo1;

    std::cout << "Digite o 2° ângulo:" << std::endl;
    std::cin >> angulo2;

    angulo3 = 180.0 - angulo1 - angulo2;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "O terceiro ângulo é: " << angulo3 << std::endl;

    return 0;
}
