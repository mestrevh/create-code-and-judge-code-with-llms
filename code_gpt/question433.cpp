/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double ipva, taxa_transito;
    std::cin >> ipva >> taxa_transito;

    double desconto = ipva * 0.05;
    double total = (ipva - desconto) + taxa_transito;

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    return 0;
}
