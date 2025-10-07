/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::set<char> letters;

    for (char c : line) {
        if (std::isalpha(c)) {
            letters.insert(std::tolower(c));
        }
    }

    for (char letter : letters) {
        std::cout << letter << '\n';
    }

    return 0;
}
