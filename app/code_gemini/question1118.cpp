/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::string base_word;
    std::cin >> base_word;

    std::vector<std::string> secondary_words;
    std::string temp_word;
    while (std::cin >> temp_word) {
        secondary_words.push_back(temp_word);
    }

    if (n <= 0 || m <= 0 || n > base_word.length() || m > base_word.length()) {
        std::cout << "TAMANHO INVALIDO\n";
        return 0;
    }

    std::string prefix = base_word.substr(0, n);
    std::string suffix = base_word.substr(m - 1);

    std::string prefix_upper = prefix;
    std::transform(prefix_upper.begin(), prefix_upper.end(), prefix_upper.begin(),
                   [](unsigned char c){ return std::toupper(c); });

    std::cout << prefix_upper << " :\n";
    for (const auto& word : secondary_words) {
        std::cout << prefix << word << "\n";
    }

    std::cout << "\n";

    std::string suffix_upper = suffix;
    std::transform(suffix_upper.begin(), suffix_upper.end(), suffix_upper.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    
    std::cout << suffix_upper << " :\n";
    for (const auto& word : secondary_words) {
        std::cout << word << suffix << "\n";
    }

    return 0;
}
