/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int broas, paes;
    std::cin >> broas >> paes;

    double total = broas * 1.50 + paes * 0.20;
    double poupanca = total * 0.10;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O valor a ser guardado na poupança será R$ " << poupanca << std::endl;

    return 0;
}
