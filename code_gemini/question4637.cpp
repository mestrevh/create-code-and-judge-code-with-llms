/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num, sum = 0;
    while (ss >> num) {
        sum += num;
    }
    std::cout << sum << std::endl;
    return 0;
}

