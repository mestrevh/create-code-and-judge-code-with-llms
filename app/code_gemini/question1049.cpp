/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double massa, altura;
    std::cin >> massa >> altura;
    double imc = massa / (altura * altura);
    std::cout << std::fixed << std::setprecision(2) << imc << std::endl;
    return 0;
}
