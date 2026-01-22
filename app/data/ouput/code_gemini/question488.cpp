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

    int count_sexta = 0;
    int count_bar = 0;
    const int total_votos = 11;

    for (int i = 0; i < total_votos; ++i) {
        std::string dia, local;
        std::cin >> dia >> local;

        std::transform(dia.begin(), dia.end(), dia.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        
        std::transform(local.begin(), local.end(), local.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (dia == "sexta") {
            count_sexta++;
        }

        if (local == "bar") {
            count_bar++;
        }
    }

    if (count_sexta > total_votos / 2) {
        std::cout << "SEXTA" << std::endl;
    } else {
        std::cout << "DOMINGO" << std::endl;
    }

    if (count_bar > total_votos / 2) {
        std::cout << "BAR" << std::endl;
    } else {
        std::cout << "PRAIA" << std::endl;
    }

    return 0;
}
