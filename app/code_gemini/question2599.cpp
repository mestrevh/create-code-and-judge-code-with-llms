/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> meses = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    std::vector<std::string> ordinais = {"Primeiro", "Segundo", "Terceiro", "Quarto"};
    std::vector<std::string> dias_semana = {"Sabado", "Domingo"};

    double min_chance = std::numeric_limits<double>::max();
    int best_mes = -1;
    int best_dia_idx = -1;

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 8; ++j) {
            double chance;
            std::cin >> chance;

            if (chance <= 0.5) {
                if (chance < min_chance) {
                    min_chance = chance;
                    best_mes = i;
                    best_dia_idx = j;
                }
            }
        }
    }

    if (best_mes == -1) {
        std::cout << "Proximo ano eu tento denovo..." << std::endl;
    } else {
        std::string ordinal_str = ordinais[best_dia_idx / 2];
        std::string dia_semana_str = dias_semana[best_dia_idx % 2];
        std::string mes_str = meses[best_mes];

        std::cout << "O melhor dia e no " << ordinal_str << " " << dia_semana_str << " de " << mes_str << std::endl;
    }

    return 0;
}
