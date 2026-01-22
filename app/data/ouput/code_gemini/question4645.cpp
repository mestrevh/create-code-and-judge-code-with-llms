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

    char letter_to_count;
    std::cin >> letter_to_count;

    std::cin.ignore();

    std::string phrase;
    std::getline(std::cin, phrase);

    int count = 0;
    char target_lower = tolower(letter_to_count);

    for (char c : phrase) {
        if (tolower(c) == target_lower) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
