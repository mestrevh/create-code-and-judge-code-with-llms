/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        int n = std::stoi(line);
        if (n == 0) break;

        std::vector<char> bits(32, '?');
        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, line);
            std::istringstream iss(line);
            std::string command;
            iss >> command;

            if (command == "CLEAR") {
                int i;
                iss >> i;
                bits[i] = '0';
            } else if (command == "SET") {
                int i;
                iss >> i;
                bits[i] = '1';
            } else if (command == "AND") {
                int i, j;
                iss >> i >> j;
                if (bits[i] == '1' && bits[j] == '1') bits[i] = '1';
                else if (bits[i] == '0' || bits[j] == '0') bits[i] = '0';
                else bits[i] = '?';
            } else if (command == "OR") {
                int i, j;
                iss >> i >> j;
                if (bits[i] == '1' || bits[j] == '1') bits[i] = '1';
                else if (bits[i] == '0' && bits[j] == '0') bits[i] = '0';
                else bits[i] = '?';
            }
        }
        for (char bit : bits) std::cout << bit;
        std::cout << std::endl;
    }
    return 0;
}
