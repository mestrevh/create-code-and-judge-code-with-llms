/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <tuple>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string nome1, nome2;
    int pontos1, saldo1, gols1;
    int pontos2, saldo2, gols2;

    std::cin >> nome1 >> pontos1 >> saldo1 >> gols1;
    std::cin >> nome2 >> pontos2 >> saldo2 >> gols2;

    std::tuple<int, int, int> stats1 = {pontos1, saldo1, gols1};
    std::tuple<int, int, int> stats2 = {pontos2, saldo2, gols2};

    if (stats1 > stats2) {
        for (char &c : nome1) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        std::cout << nome1 << std::endl;
    } else if (stats2 > stats1) {
        for (char &c : nome2) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        std::cout << nome2 << std::endl;
    } else {
        std::cout << "EMPATE" << std::endl;
    }

    return 0;
}
