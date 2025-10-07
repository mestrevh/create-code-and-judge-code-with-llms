/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double massa, altura;
    std::cout << "Digite a massa em kg e altura em m:" << std::endl;
    std::cin >> massa >> altura;
    int imc = massa / (altura * altura);
    std::cout << "IMC: " << imc << std::endl;
    return 0;
}
