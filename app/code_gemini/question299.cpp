/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int score_c = 0;
    int score_e = 0;
    int kicks_c = 0;
    int kicks_e = 0;
    int kick_result;

    for (int i = 0; i < 5; ++i) {
        std::cin >> kick_result;
        score_c += kick_result;
        kicks_c++;

        if (score_c > score_e + (5 - kicks_e)) {
            std::cout << "COMPUTACAO.RAR\n";
            return 0;
        }
        if (score_e > score_c + (5 - kicks_c)) {
            std::cout << "EDUCACAO FISICA\n";
            return 0;
        }

        std::cin >> kick_result;
        score_e += kick_result;
        kicks_e++;

        if (score_c > score_e + (5 - kicks_e)) {
            std::cout << "COMPUTACAO.RAR\n";
            return 0;
        }
        if (score_e > score_c + (5 - kicks_c)) {
            std::cout << "EDUCACAO FISICA\n";
            return 0;
        }
    }

    int kick_c_sd, kick_e_sd;
    while (std::cin >> kick_c_sd >> kick_e_sd) {
        if (kick_c_sd > kick_e_sd) {
            std::cout << "COMPUTACAO.RAR\n";
            return 0;
        }
        if (kick_e_sd > kick_c_sd) {
            std::cout << "EDUCACAO FISICA\n";
            return 0;
        }
    }

    return 0;
}
