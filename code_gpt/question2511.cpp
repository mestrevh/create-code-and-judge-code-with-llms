/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> items;
    std::set<std::string> guesses;
    std::string item, guess;

    // Lendo os 5 items da sacola
    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin, item);
        items.insert(item);
    }

    // Ignorando a linha em branco
    std::getline(std::cin, item);

    // Lendo os 6 palpites
    for (int i = 0; i < 6; ++i) {
        std::getline(std::cin, guess);
        guesses.insert(guess);
    }

    // Verificando se todos os items estão entre os palpites
    bool allGuessed = true;
    for (const auto& it : items) {
        if (guesses.find(it) == guesses.end()) {
            allGuessed = false;
            break;
        }
    }

    // Imprimindo o resultado
    if (allGuessed) {
        std::cout << "Could I be more happy?" << std::endl;
    } else {
        std::cout << "It is all just a moo point" << std::endl;
    }

    return 0;
}
