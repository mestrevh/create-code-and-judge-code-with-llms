/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    char ch;
    int total = 0;

    while (iss >> ch) {
        total += ch - 'a' + 1;
    }

    std::cout << total << std::endl;
    return 0;
}
