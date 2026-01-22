/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char nacionalidade, ocupacao;
    int qtdArmas, calibre;

    std::cin >> nacionalidade;
    std::cin >> ocupacao;
    std::cin >> qtdArmas;
    std::cin >> calibre;

    if (nacionalidade == 'E') {
        if (qtdArmas == 0) {
            std::cout << "Liberado\n";
        } else {
            std::cout << "Barrado\n";
        }
    } else if (nacionalidade == 'B') {
        if (ocupacao == 'M') {
            std::cout << "Liberado\n";
        } else if (ocupacao == 'T' || ocupacao == 'O') {
            if (qtdArmas <= 1 && calibre <= 22) {
                std::cout << "Liberado\n";
            } else {
                std::cout << "Barrado\n";
            }
        } else if (ocupacao == 'C') {
            if (qtdArmas <= 2 && calibre <= 38) {
                std::cout << "Liberado\n";
            } else {
                std::cout << "Barrado\n";
            }
        }
    }

    return 0;
}
