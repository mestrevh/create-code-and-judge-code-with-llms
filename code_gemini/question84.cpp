/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int counts[3][4][4] = {0};
    int bh_origin_count = 0;

    int o, d, t;
    while (std::cin >> o >> d >> t && (o != 0 || d != 0 || t != 0)) {
        if (o >= 1 && o <= 4 && d >= 1 && d <= 4 && t >= 1 && t <= 3) {
            counts[t - 1][o - 1][d - 1]++;
            if (o == 1) {
                bh_origin_count++;
            }
        }
    }

    std::string vehicle_names[] = {"Automovel:", "Caminhao:", "Onibus:"};

    for (int i = 0; i < 3; ++i) {
        std::cout << vehicle_names[i] << "\n";
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                std::cout << counts[i][j][k] << (k == 3 ? "" : " ");
            }
            std::cout << "\n";
        }
    }

    std::cout << "Origem Belo Horizonte: " << bh_origin_count << "\n";

    int specific_bus_count = counts[2][3][1] + counts[2][3][3];
    std::cout << "Onibus: Brasilia - Petropolis ou Barbacena: " << specific_bus_count << "\n";

    return 0;
}
