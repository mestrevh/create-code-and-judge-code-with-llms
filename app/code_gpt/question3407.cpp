/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int opcao;
    std::cin >> opcao;
    if (opcao == 1) {
        double a, b;
        std::cin >> a >> b;
        double resultado = a + b;
        std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    } else if (opcao == 2) {
        double x;
        std::cin >> x;
        double resultado = sqrt(x);
        std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    } else {
        std::cout << "Opção inválida!" << std::endl;
    }
    return 0;
}
