/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

void to_upper(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::toupper(c); });
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int pessoas;
    std::string cidade;
    int quartos;

    std::cin >> pessoas >> cidade >> quartos;

    to_upper(cidade);

    double custo_aluguel = 0.0;
    double custo_passeio_total = 0.0;

    if (cidade == "PIPA") {
        if (quartos == 2) {
            custo_aluguel = 600.0;
        } else if (quartos == 3) {
            custo_aluguel = 900.0;
        }
        custo_passeio_total = pessoas * 75.0;
    } else if (cidade == "FORTALEZA") {
        if (quartos == 3) {
            custo_aluguel = 950.0;
        } else if (quartos == 4) {
            custo_aluguel = 1120.0;
        }
        custo_passeio_total = pessoas * 60.0;
    }

    double total_viagem = custo_aluguel + custo_passeio_total;
    double valor_por_pessoa = total_viagem / pessoas;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << total_viagem << std::endl;
    std::cout << valor_por_pessoa << std::endl;

    return 0;
}
