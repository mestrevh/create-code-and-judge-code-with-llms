/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char nacionalidade, ocupacao;
    int quantidade_armas, calibre;

    while (std::cin >> nacionalidade) {
        if (nacionalidade != 'B' && nacionalidade != 'E') {
            break;
        }

        std::cin >> ocupacao >> quantidade_armas >> calibre;

        if (nacionalidade == 'E') {
            if (quantidade_armas == 0) {
                std::cout << "Liberado\n";
            } else {
                std::cout << "Barrado\n";
            }
        } else { // nacionalidade == 'B'
            if (ocupacao == 'M') {
                std::cout << "Liberado\n";
            } else if (ocupacao == 'T' || ocupacao == 'O') {
                if (quantidade_armas > 1 || (quantidade_armas == 1 && calibre > 22)) {
                    std::cout << "Barrado\n";
                } else {
                    std::cout << "Liberado\n";
                }
            } else if (ocupacao == 'C') {
                if (quantidade_armas > 2 || (quantidade_armas > 0 && calibre > 38)) {
                    std::cout << "Barrado\n";
                } else {
                    std::cout << "Liberado\n";
                }
            }
        }
    }

    std::cout << "Fim\n";

    return 0;
}
