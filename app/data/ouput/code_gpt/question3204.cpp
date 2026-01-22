/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int paes, broas;
    std::cin >> paes >> broas;

    double total = paes * 0.45 + broas * 2.25;
    double poupanca = total * 0.15;

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << poupanca << std::endl;

    return 0;
}
