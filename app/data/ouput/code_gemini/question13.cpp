/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> lines;
    std::string current_line;

    while (std::getline(std::cin, current_line)) {
        if (current_line == "the end!") {
            break;
        }
        lines.push_back(current_line);
    }

    if (!lines.empty()) {
        for (size_t i = 0; i < lines.size(); ++i) {
            for (char &c : lines[i]) {
                c = std::toupper(static_cast<unsigned char>(c));
            }
            std::cout << lines[i];
            if (i < lines.size() - 1) {
                std::cout << '\n';
            }
        }
    }

    return 0;
}
