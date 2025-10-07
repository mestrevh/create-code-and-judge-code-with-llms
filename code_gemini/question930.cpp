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

    int k;
    std::cin >> k;
    std::cin.ignore();

    int freq[256] = {0};

    for (int i = 0; i < k; ++i) {
        std::string line;
        std::getline(std::cin, line);
        for (char c : line) {
            freq[static_cast<unsigned char>(c)]++;
        }
    }

    char x;
    std::cin >> x;

    int max_freq = -1;
    char most_frequent_char = '\0';

    for (int i = 0; i < 256; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            most_frequent_char = static_cast<char>(i);
        }
    }

    int freq_x = freq[static_cast<unsigned char>(x)];

    std::cout << most_frequent_char << " " << max_freq << " " << freq_x << std::endl;

    return 0;
}
