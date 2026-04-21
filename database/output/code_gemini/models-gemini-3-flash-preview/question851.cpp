/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string word;
        bool first = true;
        while (ss >> word) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << word;
            first = false;
        }
        std::cout << std::endl;
    }

    return 0;
}