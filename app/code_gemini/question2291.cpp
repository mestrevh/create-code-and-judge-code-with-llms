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

    int m;
    std::cin >> m;

    double vida_ryu, vida_ken;
    std::cin >> vida_ryu >> vida_ken;

    double ataque_ryu = 0, defesa_ryu = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double valor;
            std::cin >> valor;
            if (i == j) {
                ataque_ryu += valor;
            }
            if (i + j == m - 1) {
                defesa_ryu += valor;
            }
        }
    }

    double ataque_ken = 0, defesa_ken = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            double valor;
            std::cin >> valor;
            if (i == j) {
                ataque_ken += valor;
            }
            if (i + j == m - 1) {
                defesa_ken += valor;
            }
        }
    }

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char acao_ryu, acao_ken;
        std::cin >> acao_ryu >> acao_ken;

        if (acao_ryu == 'A' && acao_ken == 'A') {
            if (ataque_ryu > ataque_ken) {
                vida_ken -= (ataque_ryu - ataque_ken);
            } else if (ataque_ken > ataque_ryu) {
                vida_ryu -= (ataque_ken - ataque_ryu);
            }
        } else if (acao_ryu == 'A' && acao_ken == 'D') {
            if (ataque_ryu > defesa_ken) {
                vida_ken -= (ataque_ryu - defesa_ken) / 2.0;
            }
        } else if (acao_ryu == 'D' && acao_ken == 'A') {
            if (ataque_ken > defesa_ryu) {
                vida_ryu -= (ataque_ken - defesa_ryu) / 2.0;
            }
        }
    }

    if (vida_ryu > vida_ken) {
        std::cout << "Ryu ganhou a batalha." << std::endl;
    } else if (vida_ken > vida_ryu) {
        std::cout << "Ken ganhou a batalha." << std::endl;
    } else {
        std::cout << "Houve empate." << std::endl;
    }

    return 0;
}
