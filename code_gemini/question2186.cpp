/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

int contar_vogais(std::string vogais, std::string frase) {
    int count = 0;
    for (char c : frase) {
        if (vogais.find(c) != std::string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (t--) {
        std::string vogais;
        std::getline(std::cin, vogais);

        std::string frase;
        std::getline(std::cin, frase);

        std::cout << contar_vogais(vogais, frase) << std::endl;
    }

    return 0;
}
