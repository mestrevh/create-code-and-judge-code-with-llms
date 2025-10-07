/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double massa, altura;
    std::cin >> massa >> altura;

    double imc = massa / (altura * altura);

    std::cout << std::fixed << std::setprecision(2) << imc << " ";

    if (imc < 18.5) {
        std::cout << "MAGREZA" << std::endl;
    } else if (imc < 25.0) {
        std::cout << "SAUDAVEL" << std::endl;
    } else if (imc < 30.0) {
        std::cout << "SOBREPESO" << std::endl;
    } else {
        std::cout << "OBESIDADE" << std::endl;
    }

    return 0;
}
