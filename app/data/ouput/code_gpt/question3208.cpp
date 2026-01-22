/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

int main() {
    float altura, peso, imc;
    std::cin >> altura >> peso;
    imc = peso / (altura * altura);
    imc = round(imc * 100) / 100;

    std::cout << imc << std::endl;

    if (imc < 18.5) std::cout << "Muito abaixo do peso";
    else if (imc < 24.9) std::cout << "Abaixo do peso";
    else if (imc < 29.9) std::cout << "Peso normal";
    else if (imc < 34.9) std::cout << "Acima do peso";
    else if (imc < 39.9) std::cout << "Obesidade grau I";
    else if (imc < 49.9) std::cout << "Obesidade grau II";
    else std::cout << "Obesidade grau III";
    
    return 0;
}
