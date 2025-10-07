/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int paes;
    int broas;

    std::cin >> paes;
    std::cin >> broas;

    double total_arrecadado = (paes * 0.45) + (broas * 2.25);
    double poupanca = total_arrecadado * 0.15;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << total_arrecadado << std::endl;
    std::cout << poupanca << std::endl;

    return 0;
}
