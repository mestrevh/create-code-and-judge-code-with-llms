/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string longestWord = "";
    int maxLength = 0;
    std::string line;

    while (getline(std::cin, line) && line != "0") {
        std::stringstream ss(line);
        std::string word;
        bool firstWord = true;

        while (ss >> word) {
            if (!firstWord) {
                std::cout << "-";
            }
            std::cout << word.length();
            firstWord = false;

            if (word.length() >= maxLength) {
                maxLength = word.length();
                longestWord = word;
            }
        }
        std::cout << "\n";
    }

    std::cout << "\nMaior palavra: " << longestWord << "\n";

    return 0;
}
