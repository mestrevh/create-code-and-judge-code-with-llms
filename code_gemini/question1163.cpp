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
            std::cout << "Bulbasaur" << std::endl;
            break;
        case 2:
            std::cout << "Ivysaur" << std::endl;
            break;
        case 3:
            std::cout << "Venusaur" << std::endl;
            break;
        case 4:
            std::cout << "Charmander" << std::endl;
            break;
        case 5:
            std::cout << "Charmeleon" << std::endl;
            break;
        case 6:
            std::cout << "Charizard" << std::endl;
            break;
        case 7:
            std::cout << "Squirtle" << std::endl;
            break;
        case 8:
            std::cout << "Wartortle" << std::endl;
            break;
        case 9:
            std::cout << "Blastoise" << std::endl;
            break;
        case 10:
            std::cout << "Caterpie" << std::endl;
            break;
        case 11:
            std::cout << "Metapod" << std::endl;
            break;
        case 12:
            std::cout << "Butterfree" << std::endl;
            break;
        default:
            std::cout << "Pokémon inválido no momento" << std::endl;
            break;
    }
    return 0;
}
