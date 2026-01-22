/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int codigo, quantidade;
    std::cin >> codigo >> quantidade;

    std::map<int, double> precos;
    precos[1] = 5.30;
    precos[2] = 6.00;
    precos[3] = 3.20;
    precos[4] = 2.50;

    double valor_total = precos[codigo] * quantidade;

    if (quantidade >= 15 || valor_total >= 40.0) {
        valor_total *= 0.85;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "R$ " << valor_total << std::endl;

    return 0;
}
