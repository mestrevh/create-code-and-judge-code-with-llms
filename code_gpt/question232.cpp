/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> sentences;
    std::string line;
    
    while (std::getline(std::cin, line)) {
        sentences.push_back(line);
    }

    int max_length = 0;
    for (const auto& s : sentences) {
        max_length = std::max(max_length, static_cast<int>(s.length()));
    }

    for (int i = max_length - 1; i >= 0; --i) {
        for (int j = sentences.size() - 1; j >= 0; --j) {
            if (i < sentences[j].length()) {
                std::cout << sentences[j][i];
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    
    return 0;
}
