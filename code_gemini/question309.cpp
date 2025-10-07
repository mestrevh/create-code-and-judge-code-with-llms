/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int caso = 1;
    
    while (std::cin >> N && N != 0) {
        if (caso > 1) {
            std::cout << "\n";
        }

        std::map<int, int> consumo_map;
        long long total_moradores = 0;
        long long total_consumo = 0;

        for (int i = 0; i < N; ++i) {
            int x, y;
            std::cin >> x >> y;
            total_moradores += x;
            total_consumo += y;
            consumo_map[y / x] += x;
        }

        std::cout << "Cidade# " << caso++ << ":\n";

        bool first_pair = true;
        for (const auto& pair : consumo_map) {
            if (!first_pair) {
                std::cout << " ";
            }
            std::cout << pair.second << "-" << pair.first;
            first_pair = false;
        }
        std::cout << "\n";

        double media_geral = static_cast<double>(total_consumo) / total_moradores;
        double media_truncada = floor(media_geral * 100) / 100.0;
        
        std::cout << "Consumo medio: " 
                  << std::fixed << std::setprecision(2) << media_truncada 
                  << " m3.\n";
    }

    return 0;
}
