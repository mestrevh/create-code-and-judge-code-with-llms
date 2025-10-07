/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double peso, altura;
    std::cin >> peso >> altura;
    double imc = peso / (altura * altura);
    std::cout << std::fixed << std::setprecision(1) << imc << std::endl;
    return 0;
}
