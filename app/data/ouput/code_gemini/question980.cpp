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

    if (salario < 1000.00) {
        salario *= 1.30;
    } else if (salario <= 2000.00) {
        salario *= 1.10;
    }

    std::cout << std::fixed << std::setprecision(2) << salario << std::endl;

    return 0;
}
