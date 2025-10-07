/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int familiares;
    std::string comando;
    int total_pessoas = 0;
    const double custo_por_refeicao = 14.00;

    while (true) {
        if (!(std::cin >> familiares)) {
            break;
        }
        total_pessoas += (1 + familiares);

        if (!(std::cin >> comando)) {
            break;
        }

        std::transform(comando.begin(), comando.end(), comando.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (comando == "sair") {
            break;
        }
    }

    double orcamento_total = static_cast<double>(total_pessoas) * custo_por_refeicao;

    std::cout << total_pessoas << std::endl;
    std::cout << std::fixed << std::setprecision(2) << orcamento_total << std::endl;

    return 0;
}
