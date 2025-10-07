/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double peso;
    std::cin >> peso;
    double valor = peso * 20.00;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O valor do prato será: R$ " << valor << std::endl;
    return 0;
}
