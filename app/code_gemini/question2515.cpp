/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double massa, altura;

    std::cout << "Digite a massa em Kg:" << std::endl;
    std::cin >> massa;

    std::cout << "Digite a altura em m:" << std::endl;
    std::cin >> altura;

    double imc = massa / (altura * altura);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "IMC = " << imc << std::endl;

    return 0;
}
