/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double altura, peso;
    std::cin >> altura >> peso;
    
    double imc = peso / (altura * altura);
    
    std::cout << std::fixed << std::setprecision(2) << imc << std::endl;
    
    if (imc < 17) {
        std::cout << "Muito abaixo do peso" << std::endl;
    } else if (imc < 18.5) {
        std::cout << "Abaixo do peso" << std::endl;
    } else if (imc < 25) {
        std::cout << "Peso normal" << std::endl;
    } else if (imc < 30) {
        std::cout << "Acima do peso" << std::endl;
    } else if (imc < 35) {
        std::cout << "Obesidade grau I" << std::endl;
    } else if (imc < 40) {
        std::cout << "Obesidade grau II" << std::endl;
    } else {
        std::cout << "Obesidade grau III" << std::endl;
    }
    
    return 0;
}
