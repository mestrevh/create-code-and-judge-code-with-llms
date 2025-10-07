/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double numero;
    std::cout << "Digite um numero:" << '\n';
    std::cin >> numero;
    std::cout << "O numero informado foi: " << std::fixed << std::setprecision(1) << numero << '\n';
    return 0;
}
