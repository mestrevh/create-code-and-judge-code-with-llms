/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double p_avela, p_caramelo, p_passas;
    double q_avela, q_caramelo, q_passas;

    if (!(std::cin >> p_avela >> p_caramelo >> p_passas >> q_avela >> q_caramelo >> q_passas)) {
        return 0;
    }

    double total = (p_avela * q_avela) + (p_caramelo * q_caramelo) + (p_passas * q_passas);

    std::cout << "Valor: R$" << std::fixed << std::setprecision(2) << total << std::endl;

    return 0;
}