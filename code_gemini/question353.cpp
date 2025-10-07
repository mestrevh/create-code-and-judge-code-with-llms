/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double peso, altura;
    std::cin >> peso >> altura;
    double imc = peso / (altura * altura);
    if (imc < 17) {
        std::cout << "muito abaixo do peso" << '\n';
    } else if (imc < 18.5) {
        std::cout << "abaixo do peso" << '\n';
    } else if (imc < 25) {
        std::cout << "peso normal" << '\n';
    } else if (imc < 30) {
        std::cout << "acima do peso" << '\n';
    } else if (imc < 35) {
        std::cout << "obesidade" << '\n';
    } else if (imc < 40) {
        std::cout << "obesidade severa" << '\n';
    } else {
        std::cout << "obesidade morbida" << '\n';
    }
    return 0;
}
