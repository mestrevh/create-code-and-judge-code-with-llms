/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int pontos_corinthians = 0;
    int pontos_flamengo = 0;

    int vitorias_c = 0;
    for (int i = 0; i < 5; ++i) {
        char resultado;
        std::cin >> resultado;
        if (resultado == 'c') {
            vitorias_c++;
        }
    }

    int pedro_escalado, yuri_escalado;
    std::cin >> pedro_escalado >> yuri_escalado;

    int gols_flamengo, gols_corinthians;
    std::cin >> gols_flamengo >> gols_corinthians;

    double media_flamengo, media_corinthians;
    std::cin >> media_flamengo >> media_corinthians;

    int vitorias_f = 5 - vitorias_c;
    if (vitorias_c > vitorias_f) {
        pontos_corinthians += 40;
    } else if (vitorias_f > vitorias_c) {
        pontos_flamengo += 40;
    }

    if (pedro_escalado == 1) {
        pontos_flamengo += 20;
    }

    if (yuri_escalado == 1) {
        pontos_corinthians += 20;
    }

    if (gols_flamengo > gols_corinthians) {
        pontos_flamengo += 15;
    } else {
        pontos_corinthians += 15;
    }

    if (media_flamengo >= 2.0) {
        pontos_flamengo += 10;
    }
    if (media_corinthians >= 2.0) {
        pontos_corinthians += 10;
    }

    if (pontos_corinthians > pontos_flamengo) {
        std::cout << "Pedro tem mais chances de comer o brownie\n";
        std::cout << "Pontos:" << pontos_corinthians << "\n";
    } else {
        std::cout << "Luiza tem mais chances de comer o brownie\n";
        std::cout << "Pontos:" << pontos_flamengo << "\n";
    }

    return 0;
}
