/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<char> letters;
    char letter;

    while (iss >> letter) {
        letters.push_back(letter);
    }

    std::sort(letters.begin(), letters.end());

    for (size_t i = 0; i < letters.size(); ++i) {
        std::cout << letters[i];
        if (i < letters.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
