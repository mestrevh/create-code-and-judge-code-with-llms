/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<int> counts(256, 0);
    std::string line;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        for (char c : line) {
            counts[static_cast<unsigned char>(c)]++;
        }
    }

    std::string query_string;
    std::getline(std::cin, query_string);

    for (char c : query_string) {
        if (c != ' ') {
            std::cout << c << " = " << counts[static_cast<unsigned char>(c)] << "\n";
        }
    }

    return 0;
}
