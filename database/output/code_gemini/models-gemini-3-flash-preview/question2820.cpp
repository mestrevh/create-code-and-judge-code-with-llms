/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "Digite as distancias percorridas separadas por ENTER" << std::endl;

    double distance;
    int met_count = 0;
    for (int i = 0; i < 7; ++i) {
        if (std::cin >> distance) {
            if (distance >= 8.0) {
                met_count++;
            }
        }
    }

    std::cout << "Meta alcancada em " << met_count << " dias" << std::endl;

    if (met_count >= 5) {
        std::cout << "Desempenho otimo" << std::endl;
    } else if (met_count >= 3) {
        std::cout << "Desempenho bom" << std::endl;
    } else {
        std::cout << "Desempenho ruim" << std::endl;
    }

    return 0;
}