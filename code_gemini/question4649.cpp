/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char target_char;
    std::cin >> target_char;

    std::cin.ignore();

    std::string phrase;
    std::getline(std::cin, phrase);

    int pos = -1;
    char lower_target = std::tolower(static_cast<unsigned char>(target_char));

    for (int i = 0; i < phrase.length(); ++i) {
        if (std::tolower(static_cast<unsigned char>(phrase[i])) == lower_target) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        std::cout << pos << "\n";
    } else {
        std::cout << "a frase nao possui a letra" << "\n";
    }

    return 0;
}
