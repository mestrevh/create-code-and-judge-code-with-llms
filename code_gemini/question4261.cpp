/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double base_maior, base_menor, altura;

    std::cout << "Digite o valor da base maior: " << std::endl;
    std::cin >> base_maior;

    std::cout << "Digite o valor da base menor: " << std::endl;
    std::cin >> base_menor;

    std::cout << "Digite o valor da altura: " << std::endl;
    std::cin >> altura;

    double area = ((base_maior + base_menor) * altura) / 2.0;

    int parte_inteira = static_cast<int>(area);

    std::cout << "A parte inteira da área equivale a: " << parte_inteira << std::endl;

    return 0;
}
