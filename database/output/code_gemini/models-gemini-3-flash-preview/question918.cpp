/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int canal;
    if (std::cin >> canal) {
        std::cout << "Digite um numero de um canal de tv:" << "\n";

        if (canal == 2) {
            std::cout << "SBT" << "\n";
        } else if (canal == 4) {
            std::cout << "BAND" << "\n";
        } else if (canal == 6) {
            std::cout << "REDETV!" << "\n";
        } else if (canal == 9) {
            std::cout << "RECORD" << "\n";
        } else if (canal == 13) {
            std::cout << "GLOBO" << "\n";
        } else {
            std::cout << "Canal inválido" << "\n";
        }
    }

    return 0;
}