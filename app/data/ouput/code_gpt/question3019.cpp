/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double peso;
    std::cin >> peso;
    double valor = peso * 20.0;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O valor do prato será: R$ " << valor << std::endl;
    return 0;
}
