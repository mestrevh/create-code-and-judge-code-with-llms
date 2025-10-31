/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

int main() {
    std::string input, letter;
    std::getline(std::cin, input);
    std::getline(std::cin, letter);
    
    std::vector<std::string> words;
    std::stringstream ss(input);
    std::string word;
    
    while (ss >> word) {
        words.push_back(word);
    }

    char desired_letter = std::toupper(letter[0]);
    std::vector<std::string> result;

    for (const auto& w : words) {
        if (std::toupper(w[0]) == desired_letter) {
            result.push_back(w);
        }
    }

    std::cout << result.size() << std::endl;
    for (const auto& w : result) {
        std::cout << w << std::endl;
    }

    return 0;
}
