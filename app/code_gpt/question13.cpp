/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::vector<std::string> lines;
    std::string line;

    while (true) {
        std::getline(std::cin, line);
        if (line == "the end!") break;
        lines.push_back(line);
    }

    for (size_t i = 0; i < lines.size(); i++) {
        for (char &c : lines[i]) {
            c = std::toupper(c);
        }
        std::cout << lines[i];
        if (i < lines.size() - 1) std::cout << std::endl;
    }

    return 0;
}
