/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C, N;
    std::cin >> C >> N;

    if (C <= 0) {
        std::cout << "Nao possuem caminhoes para fazer a coleta!\n";
        return 0;
    }

    double total_volume_m3 = 0.0;

    for (int i = 0; i < N; ++i) {
        int num_apartamentos;
        std::cin >> num_apartamentos;

        if (num_apartamentos > 0) {
            double vidro_L, papel_m3, plastico_L, metal_mL;
            std::cin >> vidro_L >> papel_m3 >> plastico_L >> metal_mL;

            double volume_por_apartamento = 0.0;
            volume_por_apartamento += vidro_L / 1000.0;
            volume_por_apartamento += papel_m3;
            volume_por_apartamento += plastico_L / 1000.0;
            volume_por_apartamento += metal_mL / 1000000.0;

            total_volume_m3 += volume_por_apartamento * num_apartamentos;
        }
    }

    double total_viagens = ceil(total_volume_m3 / 3.0);
    double media_viagens = ceil(total_viagens / static_cast<double>(C));

    std::cout << static_cast<int>(media_viagens) << "\n";

    return 0;
}
