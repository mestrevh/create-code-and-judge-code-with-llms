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

    int count_corte_homem = 0;
    int count_barba_homem = 0;
    double faturamento_total = 0.0;

    std::string sexo_str;
    std::string servico_str;

    while (std::cin >> sexo_str) {
        char sexo = std::tolower(sexo_str[0]);

        if (sexo != 'm' && sexo != 'f') {
            break;
        }

        std::cin >> servico_str;
        std::transform(servico_str.begin(), servico_str.end(), servico_str.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (sexo == 'm') {
            if (servico_str == "corte") {
                faturamento_total += 25.00;
                count_corte_homem++;
            } else if (servico_str == "barba") {
                faturamento_total += 15.00;
                count_barba_homem++;
            }
        } else {
            if (servico_str == "corte") {
                faturamento_total += 40.00;
            } else if (servico_str == "penteado") {
                faturamento_total += 50.00;
            } else if (servico_str == "maquiagem") {
                faturamento_total += 70.00;
            }
        }
    }

    if (count_corte_homem > count_barba_homem) {
        std::cout << "CORTE" << std::endl;
    } else if (count_barba_homem > count_corte_homem) {
        std::cout << "BARBA" << std::endl;
    } else {
        std::cout << "AMBOS" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(2) << faturamento_total << std::endl;

    return 0;
}
