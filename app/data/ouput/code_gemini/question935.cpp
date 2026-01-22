/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double n1, n2, n3;

    std::cout << "Informe a primeira nota:" << std::endl;
    std::cin >> n1;

    std::cout << "Informe a segunda nota:" << std::endl;
    std::cin >> n2;

    std::cout << "Informe a terceira nota:" << std::endl;
    std::cin >> n3;

    double media = (n1 + n2 + n3) / 3.0;

    std::cout << std::fixed << std::setprecision(1);

    if (media >= 7.0) {
        std::cout << "Aprovado com media " << media << std::endl;
    } else if (media >= 5.0) {
        std::cout << "Recuperacao com media " << media << std::endl;
    } else {
        std::cout << "Reprovado com media " << media << std::endl;
    }

    return 0;
}
