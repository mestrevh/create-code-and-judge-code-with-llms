/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    char letra;
    std::string frase;

    std::cin >> letra;
    std::cin.ignore();
    std::getline(std::cin, frase);

    int contador = 0;
    for (char c : frase) {
        if (c == letra) {
            contador++;
        }
    }

    std::cout << contador << std::endl;

    return 0;
}
