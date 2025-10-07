/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double valor_total;
    std::cin >> valor_total;
    double prestacao = floor(valor_total / 3.0);
    double entrada = valor_total - 2.0 * prestacao;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << entrada << std::endl;
    std::cout << prestacao << std::endl;
    std::cout << prestacao << std::endl;
    return 0;
}
