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

    std::string line;
    while (std::getline(std::cin, line) && line != "NAO QUERO MAIS") {
        int space_count = 0;
        int a_count = 0;
        int pair_counts[26][26] = {};

        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') {
                space_count++;
            }
            if (tolower(line[i]) == 'a') {
                a_count++;
            }

            if (i + 1 < line.length()) {
                char c1 = line[i];
                char c2 = line[i + 1];
                if (isalpha(c1) && isalpha(c2)) {
                    pair_counts[tolower(c1) - 'a'][tolower(c2) - 'a']++;
                }
            }
        }

        int max_freq = 0;
        std::string max_pair = "";

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (pair_counts[i][j] > max_freq) {
                    max_freq = pair_counts[i][j];
                    max_pair = "";
                    max_pair += (char)('a' + i);
                    max_pair += (char)('a' + j);
                }
            }
        }

        std::cout << space_count << std::endl;
        std::cout << a_count << std::endl;

        if (max_freq > 0) {
            std::cout << max_freq << std::endl;
            std::cout << max_pair << std::endl;
        } else {
            std::cout << "NENHUM PAR" << std::endl;
        }
    }

    return 0;
}
