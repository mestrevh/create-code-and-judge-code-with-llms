/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double a, b;
    std::cin >> a >> b;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Produto: " << a * b << std::endl;
    std::cout << "Razao: " << a / b << std::endl;

    return 0;
}
