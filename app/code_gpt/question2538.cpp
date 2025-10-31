/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int quantidade;
    std::cout << "Digite a quantidade de macas:\n";
    std::cin >> quantidade;

    double preco = (quantidade < 12) ? 0.30 : 0.25;
    double total = quantidade * preco;

    std::cout << "Valor total: R$ " << std::fixed << std::setprecision(2) << total << std::endl;

    return 0;
}
