/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::map<std::string, std::string> dictionary;
    for (int i = 0; i < n; ++i) {
        std::string original, separator, translation;
        std::cin >> original >> separator >> translation;
        dictionary[original] = translation;
    }

    std::string first_word_in_line;
    while (std::cin >> first_word_in_line && first_word_in_line != "*") {
        
        std::string rest_of_line;
        std::getline(std::cin, rest_of_line);
        
        std::string full_line = first_word_in_line + rest_of_line;

        std::stringstream ss(full_line);
        std::string word;
        bool first_word_on_output = true;

        while (ss >> word) {
            if (!first_word_on_output) {
                std::cout << " ";
            }
            
            auto it = dictionary.find(word);
            if (it != dictionary.end()) {
                std::cout << it->second;
            } else {
                std::cout << word;
            }
            first_word_on_output = false;
        }
        std::cout << "\n";
    }

    return 0;
}
