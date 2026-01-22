/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int sim_count = 0;
    int nao_count = 0;
    int nulo_count = 0;
    std::string vote;

    while (std::cin >> vote) {
        std::transform(vote.begin(), vote.end(), vote.begin(),
                       [](unsigned char c){ return std::toupper(c); });

        if (vote == "ENCERRAR") {
            break;
        }

        if (vote == "SIM") {
            sim_count++;
        } else if (vote == "NAO") {
            nao_count++;
        } else if (vote == "NULO") {
            nulo_count++;
        }
    }

    if (sim_count > (nao_count + nulo_count)) {
        std::cout << "COM FOGOS" << std::endl;
    } else {
        std::cout << "SEM FOGOS" << std::endl;
    }

    return 0;
}
