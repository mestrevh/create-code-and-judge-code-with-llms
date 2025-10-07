/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double dinheiro;
    int p1_status, p2_status;
    double preco1, preco2;
    double divida;

    std::cin >> dinheiro;
    std::cin >> p1_status >> p2_status;
    std::cin >> preco1 >> preco2;
    std::cin >> divida;

    double custo_reparo = 0.0;

    if (p1_status == 1 && p2_status == 1) {
        custo_reparo = std::min(preco1, preco2) + std::max(preco1, preco2) * 0.88;
    } else if (p1_status == 1) {
        custo_reparo = preco1;
    } else if (p2_status == 1) {
        custo_reparo = preco2;
    }

    double custo_total = custo_reparo + divida;

    std::cout << std::fixed << std::setprecision(2);

    if (dinheiro >= custo_total) {
        std::cout << "Sherliro livre do Jabbavitz e podendo voar" << std::endl;
    } else if (dinheiro >= custo_reparo) {
        double falta = custo_total - dinheiro;
        std::cout << "Sherliro consertou mas ta lascado com o Jabbavitz" << std::endl;
        std::cout << "faltam " << falta << " Napoleocoins" << std::endl;
    } else {
        double falta = custo_total - dinheiro;
        std::cout << "Sherliro vai ser perseguido hoje e ainda ta sem nave" << std::endl;
        std::cout << "faltam " << falta << " Napoleocoins" << std::endl;
    }

    return 0;
}
