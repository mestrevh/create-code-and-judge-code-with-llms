/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double a, b;
    std::cin >> a >> b;
    double resultado = a / b;
    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    return 0;
}
