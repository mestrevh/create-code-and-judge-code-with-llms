/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::cin >> line) {
        std::list<char> text;
        auto cursor = text.begin();

        for (char c : line) {
            if (c == '[') {
                cursor = text.begin();
            } else if (c == ']') {
                cursor = text.end();
            } else {
                cursor = text.insert(cursor, c);
                cursor++;
            }
        }

        for (char c : text) {
            std::cout << c;
        }
        std::cout << '\n';
    }

    return 0;
}
