/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> all_words(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> all_words[i];
    }

    char target_letter;
    std::cin >> target_letter;

    std::vector<std::string> matching_words;
    for (const std::string& word : all_words) {
        if (!word.empty() && word[0] == target_letter) {
            matching_words.push_back(word);
        }
    }

    std::cout << matching_words.size() << '\n';
    for (const std::string& word : matching_words) {
        std::cout << word << '\n';
    }

    return 0;
}
