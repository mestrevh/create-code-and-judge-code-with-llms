/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double peso, altura;
    std::cin >> peso >> altura;
    double imc = peso / (altura * altura);
    std::cout << std::fixed << std::setprecision(2) << imc << std::endl;
    if (imc < 18 || imc > 25) {
        std::cout << "atencao" << std::endl;
    } else {
        std::cout << "normal" << std::endl;
    }
    return 0;
}
