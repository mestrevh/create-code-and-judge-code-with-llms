/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int hoteis_jp_5_estrelas = 0;
    int soma_estrelas_cg = 0;
    int count_cg = 0;
    int pousadas_rio_tinto = 0;

    for (int i = 0; i < 10; ++i) {
        std::string tipo;
        int estrelas;
        std::string cidade;

        std::cin >> tipo >> estrelas;
        std::getline(std::cin >> std::ws, cidade);

        std::transform(tipo.begin(), tipo.end(), tipo.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        std::transform(cidade.begin(), cidade.end(), cidade.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (tipo == "hotel" && estrelas == 5 && cidade == "joão pessoa") {
            hoteis_jp_5_estrelas++;
        }

        if (cidade == "campina grande") {
            soma_estrelas_cg += estrelas;
            count_cg++;
        }

        if (tipo == "pousada" && cidade == "rio tinto") {
            pousadas_rio_tinto++;
        }
    }

    int media_cg = 0;
    if (count_cg > 0) {
        media_cg = soma_estrelas_cg / count_cg;
    }

    std::cout << hoteis_jp_5_estrelas << std::endl;
    std::cout << media_cg << std::endl;
    std::cout << pousadas_rio_tinto << std::endl;

    return 0;
}
