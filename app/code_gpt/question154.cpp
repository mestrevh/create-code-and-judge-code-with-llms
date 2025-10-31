/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int C;
    std::cin >> C;
    std::string mapa;
    std::cin >> mapa;

    int total_paineis = 0;

    for (char bloco : mapa) {
        if (bloco == 'P') {
            total_paineis += 2;
        } else if (bloco == 'C') {
            total_paineis += 2;
        } else if (bloco == 'A') {
            total_paineis += 1;
        } else if (bloco == 'D') {
            total_paineis += 0;
        }
    }

    std::cout << total_paineis << std::endl;

    return 0;
}
