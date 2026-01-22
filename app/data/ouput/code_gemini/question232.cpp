/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> lines;
    std::string line;
    size_t max_len = 0;

    while (std::getline(std::cin, line)) {
        lines.push_back(line);
        if (line.length() > max_len) {
            max_len = line.length();
        }
    }

    for (size_t i = 0; i < max_len; ++i) {
        for (int j = lines.size() - 1; j >= 0; --j) {
            if (i < lines[j].length()) {
                std::cout << lines[j][i];
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}
