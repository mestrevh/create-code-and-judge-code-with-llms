/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> words;
    std::string current_word = "";
    int letter_count = 0;
    std::string token;

    while (std::cin >> token && token != "fim") {
        if (token == "-") {
            if (!current_word.empty()) {
                words.push_back(current_word);
                current_word = "";
            }
        } else {
            current_word += token;
            letter_count++;
        }
    }

    if (!current_word.empty()) {
        words.push_back(current_word);
    }

    std::string sentence = "";
    if (!words.empty()) {
        sentence = words[0];
        for (size_t i = 1; i < words.size(); ++i) {
            sentence += " ";
            sentence += words[i];
        }
    }

    std::cout << "A palavra é: " << sentence << std::endl;
    std::cout << "Ela tem " << words.size() << " palavras" << std::endl;
    std::cout << "Ela tem " << letter_count << " letras" << std::endl;

    return 0;
}
