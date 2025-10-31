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
    int cinema_votos = 0;
    int boliche_votos = 0;
    for (int i = 0; i < 7; ++i) {
        std::string voto;
        std::cin >> voto;
        std::transform(voto.begin(), voto.end(), voto.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (voto == "cinema") {
            cinema_votos++;
        } else {
            boliche_votos++;
        }
    }
    if (cinema_votos > boliche_votos) {
        std::cout << "CINEMA\n";
    } else {
        std::cout << "BOLICHE\n";
    }
    return 0;
}
