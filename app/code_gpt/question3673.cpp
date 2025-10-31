/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string removeAdjacentDuplicates(const std::string& txt) {
    if (txt.size() < 2) return txt;
    if (txt[0] == txt[1]) return removeAdjacentDuplicates(txt.substr(1));
    return txt[0] + removeAdjacentDuplicates(txt.substr(1));
}

int main() {
    std::string line;
    while (std::getline(std::cin, line) && line != "*") {
        std::cout << removeAdjacentDuplicates(line) << std::endl;
    }
    return 0;
}
