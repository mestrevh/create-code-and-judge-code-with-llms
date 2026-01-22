/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int forca, inteligencia, destreza, furtividade, peso;

    std::cin >> forca >> inteligencia >> destreza >> furtividade >> peso;

    if (forca > 10 && inteligencia < 5 && destreza < 5 && furtividade < 5 && peso > 5) {
        std::cout << "Orc\n";
    } else if (forca > 5 && inteligencia > 5 && destreza > 5 && furtividade > 5 && peso < 5) {
        std::cout << "Paladin\n";
    } else if (forca < 5 && inteligencia > 5 && furtividade > 5 && peso < 5) {
        std::cout << "Mage\n";
    } else if (forca > 5 && destreza > 5 && peso > 5) {
        std::cout << "Knight\n";
    }

    return 0;
}
