/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double peso, altura, imc;
    std::cin >> peso >> altura;
    imc = peso / (altura * altura);
    std::cout << std::fixed << std::setprecision(1) << imc << std::endl;
    return 0;
}
