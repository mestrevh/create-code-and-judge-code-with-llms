/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int dias_meta_cumprida = 0;
    
    for (int i = 0; i < 7; ++i) {
        double distancia;
        std::cin >> distancia;
        if (distancia >= 8.0) {
            dias_meta_cumprida++;
        }
    }

    if (dias_meta_cumprida >= 5) {
        std::cout << "Desempenho otimo\n";
    } else if (dias_meta_cumprida >= 3) {
        std::cout << "Desempenho razoavel\n";
    } else {
        std::cout << "Desempenho ruim\n";
    }

    return 0;
}
