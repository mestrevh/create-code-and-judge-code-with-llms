/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double massa, altura;
    std::cout << "Digite a massa em kg e altura em m:" << std::endl;
    std::cin >> massa >> altura;

    int imc = static_cast<int>(massa / (altura * altura));
    std::cout << "IMC: " << imc << std::endl;

    return 0;
}
