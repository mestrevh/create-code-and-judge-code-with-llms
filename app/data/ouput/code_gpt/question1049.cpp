/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double massa, altura, imc;
    std::cin >> massa >> altura;
    imc = massa / (altura * altura);
    std::cout << std::fixed << std::setprecision(2) << imc << std::endl;
    return 0;
}
