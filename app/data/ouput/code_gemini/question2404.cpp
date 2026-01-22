/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double salario;
    std::cin >> salario;
    double novo_salario = salario * 1.25;
    std::cout << std::fixed << std::setprecision(2) << novo_salario << std::endl;
    return 0;
}
