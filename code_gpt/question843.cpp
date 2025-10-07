/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::string word;
    int count = 0;
    while (iss >> word) {
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}
