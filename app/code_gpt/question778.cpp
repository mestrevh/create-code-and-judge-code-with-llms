/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <deque>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::deque<std::string> result;
        std::string current;
        bool atHome = false;

        for (char c : line) {
            if (c == '[') {
                if (atHome) {
                    result.push_back(current);
                    current.clear();
                } else {
                    result.push_front(current);
                    current.clear();
                }
                atHome = true;
            } else if (c == ']') {
                if (atHome) {
                    result.push_back(current);
                    current.clear();
                }
                atHome = false;
            } else if (c == '_' || c == '-') {
                current += '_';
            } else {
                current += c;
            }
        }
        if (atHome) {
            result.push_back(current);
        } else {
            result.push_front(current);
        }

        for (const auto& part : result) {
            std::cout << part;
        }
        std::cout << std::endl;
    }
    return 0;
}
