/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string letter_soup;
    std::cin >> letter_soup;

    int soup_freq[256] = {0};
    for (char c : letter_soup) {
        soup_freq[static_cast<unsigned char>(c)]++;
    }

    int n;
    std::cin >> n;

    int formed_words_count = 0;

    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;

        int word_freq[256] = {0};
        for (char c : word) {
            word_freq[static_cast<unsigned char>(c)]++;
        }

        bool can_form = true;
        for (int j = 0; j < 256; ++j) {
            if (soup_freq[j] < word_freq[j]) {
                can_form = false;
                break;
            }
        }

        if (can_form) {
            formed_words_count++;
            for (int j = 0; j < 256; ++j) {
                soup_freq[j] -= word_freq[j];
            }
        }
    }

    std::cout << "E possivel formar " << formed_words_count << " palavras com esse conjunto\n";

    return 0;
}
