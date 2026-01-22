/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int total_caminhoes = 0;
    int preco_total = 0;
    int dias_maximos = 0;

    for (int i = 0; i < n; ++i) {
        int t, e, d;
        std::cin >> t >> e >> d;

        int caminhoes_dest = 0;
        int preco_dest = 0;
        int dias_dest = 0;

        if (e == 0) { // Normal
            caminhoes_dest = (t + 9) / 10;
            preco_dest = caminhoes_dest * 500;
            dias_dest = (d + 99) / 100;
        } else { // Expressa
            caminhoes_dest = (t + 4) / 5;
            preco_dest = caminhoes_dest * 1200;
            dias_dest = (d + 249) / 250;
        }

        total_caminhoes += caminhoes_dest;
        preco_total += preco_dest;
        dias_maximos = std::max(dias_maximos, dias_dest);
    }

    std::cout << total_caminhoes << " " << preco_total << " " << dias_maximos << std::endl;

    return 0;
}
