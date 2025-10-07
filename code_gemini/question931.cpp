/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(2);

    std::string nome_candidato;
    while (std::cin >> nome_candidato && nome_candidato != "FIM") {
        int num_midias;
        std::cin >> num_midias;

        double custo_total = 0.0;

        for (int i = 0; i < num_midias; ++i) {
            std::string tipo_midia;
            std::cin >> tipo_midia;

            if (tipo_midia == "internet") {
                custo_total += 3000.0;
            } else if (tipo_midia == "revista") {
                custo_total += 750.0;
            } else if (tipo_midia == "outdoor") {
                custo_total += 1500.0;
            } else if (tipo_midia == "radio") {
                std::string tipo_radio;
                std::cin >> tipo_radio;
                if (tipo_radio == "fm") {
                    custo_total += 500.0;
                } else { // am
                    custo_total += 300.0;
                }
            } else if (tipo_midia == "tv") {
                int hora;
                std::cin >> hora;
                if (hora > 20) {
                    custo_total += 2000.0;
                } else {
                    custo_total += 1200.0;
                }
            }
        }

        std::cout << nome_candidato << ": " << custo_total << std::endl;
    }

    return 0;
}
