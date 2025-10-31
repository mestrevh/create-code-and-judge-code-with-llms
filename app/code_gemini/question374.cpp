/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double salario;
    std::cin >> salario;
    double bonus = salario * 0.75;
    if (bonus < 2000.0) {
        std::cout << "ARGENTINA" << std::endl;
    } else if (bonus <= 3000.0) {
        std::cout << "ESPANHA" << std::endl;
    } else {
        std::cout << "ALEMANHA" << std::endl;
    }
    return 0;
}
