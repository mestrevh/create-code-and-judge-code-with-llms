/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p;
    std::cin >> p;
    switch (p) {
        case 1:
            std::cout << "Bulbassauro\n";
            break;
        case 2:
            std::cout << "Ivyssauro\n";
            break;
        case 3:
            std::cout << "Venossauro\n";
            break;
        case 4:
            std::cout << "Charmander\n";
            break;
        case 5:
            std::cout << "Charmeleon\n";
            break;
        case 6:
            std::cout << "Charizard\n";
            break;
        case 7:
            std::cout << "Squirtle\n";
            break;
        case 8:
            std::cout << "Wartortle\n";
            break;
        case 9:
            std::cout << "Blastoise\n";
            break;
        case 10:
            std::cout << "Caterpie\n";
            break;
        case 11:
            std::cout << "Metapod\n";
            break;
        case 12:
            std::cout << "Butterfree\n";
            break;
        default:
            std::cout << "Pokemon invalido no momento\n";
            break;
    }
    return 0;
}
