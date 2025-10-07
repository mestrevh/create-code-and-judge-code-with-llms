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
    std::string input_line;
    while (std::getline(std::cin, input_line)) {
        std::list<char> beiju_text;
        auto cursor = beiju_text.begin();
        for (char c : input_line) {
            if (c == '[') {
                cursor = beiju_text.begin();
            } else if (c == ']') {
                cursor = beiju_text.end();
            } else {
                beiju_text.insert(cursor, c);
            }
        }
        for (char c : beiju_text) {
            std::cout << c;
        }
        std::cout << '\n';
    }
    return 0;
}
