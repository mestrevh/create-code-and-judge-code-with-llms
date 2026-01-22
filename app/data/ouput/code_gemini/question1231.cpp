/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int estoque[4];
    std::cin >> estoque[0] >> estoque[1] >> estoque[2] >> estoque[3];

    const int NUQUES_POR_SICLE = 29;
    const int SICLES_POR_GALEAO = 17;
    const int NUQUES_POR_GALEAO = NUQUES_POR_SICLE * SICLES_POR_GALEAO;

    int precos_em_nuques[4] = {
        5 * NUQUES_POR_GALEAO + 16 * NUQUES_POR_SICLE + 22, // Fenix
        1 * NUQUES_POR_GALEAO + 2 * NUQUES_POR_SICLE + 28,  // Dragao
        2 * NUQUES_POR_GALEAO + 10 * NUQUES_POR_SICLE + 12, // Unicornio
        3 * NUQUES_POR_GALEAO + 10 * NUQUES_POR_SICLE + 0   // Testralio
    };

    std::string nomes[4] = {"Fenix", "Dragao", "Unicornio", "Testralio"};

    long long total_nuques_caixa = 0;
    std::string venda;

    while (std::cin >> venda && venda != "FIM") {
        if (venda == "Fenix") {
            estoque[0]--;
            total_nuques_caixa += precos_em_nuques[0];
        } else if (venda == "Dragao") {
            estoque[1]--;
            total_nuques_caixa += precos_em_nuques[1];
        } else if (venda == "Unicornio") {
            estoque[2]--;
            total_nuques_caixa += precos_em_nuques[2];
        } else if (venda == "Testralio") {
            estoque[3]--;
            total_nuques_caixa += precos_em_nuques[3];
        }
    }

    for (int i = 0; i < 4; ++i) {
        std::cout << nomes[i] << " " << estoque[i] << std::endl;
    }

    long long galeoes = total_nuques_caixa / NUQUES_POR_GALEAO;
    long long resto_apos_galeoes = total_nuques_caixa % NUQUES_POR_GALEAO;
    long long sicles = resto_apos_galeoes / NUQUES_POR_SICLE;
    long long nuques = resto_apos_galeoes % NUQUES_POR_SICLE;

    std::cout << galeoes << " " << sicles << " " << nuques << std::endl;

    return 0;
}
